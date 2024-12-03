#include <iostream>

using namespace std;

struct Vec {
    int capacity = 1;
    int size = 0;
    int* data = new int[capacity];
};

void increase_capacity(Vec& v, int new_capacity) {
    if (new_capacity > v.capacity) {
        v.capacity = new_capacity;
        int* new_data = new int[v.capacity];
        for (int i = 0; i < v.size; i++) {
            new_data[i] = v.data[i];
        }
        delete[] v.data;
        v.data = new_data;
    }
}

void push_back(Vec& v, int value) {
    if (v.size == v.capacity) {
        increase_capacity(v, v.capacity * 2);
    }
    v.data[v.size] = value;
    v.size++;
}

void pop_back(Vec& v) {
    if (v.size > 0) {
        v.size--;
    }
}

void print(const Vec& v) {
    for (int i = 0; i < v.size; i++) {
        cout << v.data[i] << " ";
    }
    cout << endl;
}

int main() {
    Vec v;
    push_back(v, 1);
    push_back(v, 2);
    push_back(v, 3);
    push_back(v, 4);
    push_back(v, 5);
    push_back(v, 6);
    push_back(v, 7);
    push_back(v, 8);
    push_back(v, 9);
    push_back(v, 10);
    push_back(v, 11);
    push_back(v, 12);
    push_back(v, 13);
    push_back(v, 14);
    push_back(v, 15);
    push_back(v, 16);
    push_back(v, 17);
    push_back(v, 18);
    push_back(v, 19);
    push_back(v, 20);

    print(v);

    pop_back(v);
    pop_back(v);
    pop_back(v);
    pop_back(v);

    print(v);

    increase_capacity(v, 100);

    print(v);

    return 0;
}
