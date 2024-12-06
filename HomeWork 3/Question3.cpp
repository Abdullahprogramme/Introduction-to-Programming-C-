#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>


#define MAX_WORKERS 4
#define MAX_TASKS 10
#define MAX_TASKS_PER_WORKER 3

using namespace std;

struct Task {
    int taskID;        // Unique ID for the task
    int level;         // Task level (1, 2, or 3)
    int estTime;       // Estimated time for the task
    int loggedTime;    // Time logged for the task
};

struct Worker {
    int workerID;          // Unique ID for the worker
    int totalLoggedTime;   // Total time logged by the worker
    Task tasks[3];         // Array to store up to 3 tasks for the worker
    int taskCount;         // Number of tasks currently assigned
};

// Function prototypes
void AssignTask(Worker* workerPtr, int tskID);
void AssignBulTasks(int ws, Worker workerList[], int ts, Task taskList[]);
void LogTaskTime(Worker* workerPtr, Task* tskPtr, int time);
void PrintTaskTimeLog(Task tsk);
void PrintWorkerTaskList(Worker worker);
void PrintWorkerTimeDetails(Worker worker);
void PrintWorkersInTxtFile(int ws, Worker workerList[], FILE* fptr);
Worker NewWorker();
Task NewTask();

int main() {
    int numWorkers, numTasks;

    cout << "Enter the number of workers: ";
    cin >> numWorkers;
    cout << "Enter the number of tasks: ";
    cin >> numTasks;

    Worker workers[MAX_WORKERS];
    Task tasks[MAX_TASKS];

    // Initialize workers
    for (int i = 0; i < numWorkers; i++) {
        workers[i] = NewWorker();
        workers[i].workerID = i + 1;
    }

    // Initialize tasks
    for (int i = 0; i < numTasks; i++) {
        tasks[i] = NewTask();
        tasks[i].taskID = i + 1;
        tasks[i].level = (i % 3) + 1;
        tasks[i].estTime = (i % 3 == 0) ? 9 : (i % 3 == 1) ? 7 : 3;
    }

    cout << "Assigning tasks..." << endl;

    // Assign tasks to workers
    AssignBulTasks(numWorkers, workers, numTasks, tasks);

    // Log task time
    int workerID, taskID, loggedTime;
    cout << "Log Time:" << endl;
    cout << "Enter Worker ID: ";
    cin >> workerID;
    cout << "Enter Task ID: ";
    cin >> taskID;
    cout << "Enter Time Logged: ";
    cin >> loggedTime;

    LogTaskTime(&workers[workerID - 1], &workers[workerID - 1].tasks[taskID % 3], loggedTime);

    // Print task update
    cout << endl << "Task " << taskID << " Updated" << endl;
    PrintTaskTimeLog(workers[workerID - 1].tasks[taskID % 3]);
    cout << "- Remaining Time: " << workers[workerID - 1].tasks[taskID % 3].estTime - workers[workerID - 1].tasks[taskID % 3].loggedTime << " hours" << endl;

    // Print worker task list in txt file
    FILE* fptr = fopen("worker_tasks.txt", "w");
    if (fptr == NULL) {
        cout << "Error opening file." << endl;
        return 1;
    }

    PrintWorkersInTxtFile(numWorkers, workers, fptr);
    fclose(fptr);

    return 0;
}

// Function definitions

void AssignTask(Worker* workerPtr, int tskID) {
    // Check if worker has maximum tasks
    if (workerPtr->taskCount >= MAX_TASKS_PER_WORKER) {
        cout << "Worker " << workerPtr->workerID << " already has maximum tasks." << endl;
        return;
    }
    workerPtr->tasks[workerPtr->taskCount].taskID = tskID;
    workerPtr->taskCount++;
}

void AssignBulTasks(int ws, Worker workerList[], int ts, Task taskList[]) {
    int minTasksPerWorker = ts / ws;    // Minimum tasks every worker gets
    int extraTasks = ts % ws;          // Tasks that need to be distributed evenly
    int taskIndex = 0;


    // Assign tasks to workers
    for (int i = 0; i < ws; i++) {
        int tasksToAssign = minTasksPerWorker + (extraTasks > 0 ? 1 : 0); // Adjust tasks based on extra tasks
        extraTasks = (extraTasks > 0) ? extraTasks - 1 : 0;

        // Assign tasks to worker where checking if worker has maximum tasks and if there are tasks left
        for (int j = 0; j < tasksToAssign && taskIndex < ts && MAX_TASKS_PER_WORKER > workerList[i].taskCount; j++) {
            workerList[i].tasks[workerList[i].taskCount] = taskList[taskIndex];
            workerList[i].taskCount++;
            taskIndex++;
        }
    }

    // Print assigned tasks for each worker
    for (int i = 0; i < ws; i++) {
        cout << "Worker " << workerList[i].workerID << ":" << endl;
        for (int j = 0; j < workerList[i].taskCount; j++) {
            Task &t = workerList[i].tasks[j];
            cout << "- Task " << t.taskID << ": Level " << setfill('0') << setw(2) << t.level
                 << ", Est. Time: " << t.estTime << " hours" << endl;
        }
        cout << endl;
    }

    // Print leftover tasks, if any
    if (taskIndex < ts) {
        cout << "Leftover Tasks:" << endl;
        for (int i = taskIndex; i < ts; i++) {
            cout << "- Task " << taskList[i].taskID << ": Level " << setfill('0') << setw(2)
                 << taskList[i].level << ", Est. Time: " << taskList[i].estTime << " hours" << endl;
        }
    }
}


void LogTaskTime(Worker* workerPtr, Task* tskPtr, int time) {
    // finding the task in the worker's task list using the task ID
    for (int i = 0; i < workerPtr->taskCount; i++) {
        if (workerPtr->tasks[i].taskID == tskPtr->taskID) {
            workerPtr->tasks[i].loggedTime += time;
            workerPtr->totalLoggedTime += time;
            break;
        }
    }
}

void PrintTaskTimeLog(Task tsk) { // Print task details
    cout << "Task " << tsk.taskID << ": Level " << tsk.level << endl;
    cout << "- Estimated Time: " << tsk.estTime << " hours" << endl;
    cout << "- Logged Time: " << tsk.loggedTime << " hours" << endl;
}

void PrintWorkerTaskList(Worker worker) { // Print worker's task list
    cout << "Worker " << worker.workerID << " Task List:" << endl;
    for (int i = 0; i < worker.taskCount; i++) {
        cout << "- Task " << worker.tasks[i].taskID << ": Level " << worker.tasks[i].level
             << ", Est. Time: " << worker.tasks[i].estTime << " hours" << endl;
    }
}

void PrintWorkerTimeDetails(Worker worker) {
    cout << "Worker " << worker.workerID << " Summary:" << endl;

    // calculate total time assigned
    int totalTimeAssigned = 0;
    for (int i = 0; i < worker.taskCount; i++) {
        totalTimeAssigned += worker.tasks[i].estTime;
    }

    // print worker details
    cout << "- Total Time Assigned: " << totalTimeAssigned << " hours" << endl;
    cout << "- Total Logged Time: " << worker.totalLoggedTime << " hours" << endl;
    cout << "- Remaining Time: " << totalTimeAssigned - worker.totalLoggedTime << " hours" << endl;
}

void PrintWorkersInTxtFile(int ws, Worker workerList[], FILE* fptr) {
    for (int i = 0; i < ws; i++) {
        // Print worker details in the file, using the C file I/O functions
        fprintf(fptr, "Worker %d:\n", workerList[i].workerID);
        for (int j = 0; j < workerList[i].taskCount; j++) {
            fprintf(fptr, "- Task %d: Level %d, Est. Time: %d hours, Logged Time: %d hours\n",
                    workerList[i].tasks[j].taskID, workerList[i].tasks[j].level,
                    workerList[i].tasks[j].estTime, workerList[i].tasks[j].loggedTime);
        }
        fprintf(fptr, "\n");
    }
}

Worker NewWorker() {
    Worker worker = {0, 0, {}, 0}; // Initialize worker with 0 values
    return worker;
}

Task NewTask() {
    Task task = {0, 0, 0, 0}; // Initialize task with 0 values
    return task;
}
