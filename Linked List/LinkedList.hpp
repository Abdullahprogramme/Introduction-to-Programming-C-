#include <iostream>
using namespace std;

struct LinkedListNode{
    int data;
    LinkedListNode* next;
};

struct LinkedList{
    LinkedListNode* head;
    LinkedListNode* tail;
    int size;
};

void init(LinkedList* list){
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void add(LinkedList* list, int data){
    LinkedListNode* node = new LinkedListNode;
    node->data = data;
    // adding in between nodes in order
    if(list->head == NULL){
        node->next = NULL;
        list->head = node;
        list->tail = node;
    }else{
        LinkedListNode* current = list->head;
        if (current->data >= data) {
            node->next = list->head;
            list->head = node;
        } else {
            while(current->next != NULL && current->next->data < data){
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
            if(node->next == NULL){
                list->tail = node;
            }
        }
    }
    list->size++;
}

void add_first(LinkedList* list, int data){
    LinkedListNode* node = new LinkedListNode;
    node->data = data;
    node->next = list->head;
    list->head = node;
    if(list->tail == NULL){
        list->tail = node;
    }
    list->size++;
}

void add_last(LinkedList* list, int data){
    LinkedListNode* node = new LinkedListNode;
    node->data = data;
    node->next = NULL;
    if(list->tail == NULL){
        list->head = node;
        list->tail = node;
    }else{
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void delete_last(LinkedList* list){
    if(list->head == NULL){
        return;
    }
    if(list->head == list->tail){
        delete list->head;
        list->head = NULL;
        list->tail = NULL;
        return;
    }
    LinkedListNode* current = list->head;
    while(current->next != list->tail){
        current = current->next;
    }
    delete list->tail;
    list->tail = current;
    list->tail->next = NULL;

    list->size--;
}

void delete_some_value(LinkedList* list, int value){
    if(list->head == NULL){
        return;
    }
    if(list->head->data == value){
        LinkedListNode* temp = list->head;
        list->head = list->head->next;
        delete temp;
        return;
    }
    LinkedListNode* current = list->head;
    while(current->next != NULL && current->next->data != value){
        current = current->next;
    }
    if(current->next == NULL){
        return;
    }
    LinkedListNode* temp = current->next;
    current->next = current->next->next;
    delete temp;

    list->size--;
}

void delete_first(LinkedList* list){
    if(list->head == NULL){
        return;
    }
    LinkedListNode* temp = list->head;
    list->head = list->head->next;
    delete temp;
    list->size--;
}

void print(LinkedList* list){
    LinkedListNode* current = list->head;
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Size: " << list->size << endl << endl;
}

