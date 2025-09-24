#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX_SIZE = 100; // Maximum size of the priority queue

struct Item
{
    string Name;
    int Priority;
    string Code;
};

void swap(Item& a, Item& b) {
    Item temp = a;
    a = b;
    b = temp;
}

void heapifyUp(Item heap[], int size, int index) {

    while (index > 0) {
            if(index>=0){
                // std::cout << index << std::endl;
            }
        int parent = (index - 1) / 2;
        if (heap[index].Priority > heap[parent].Priority) {
                // cout << "\nswap" << std::endl;
                // cout << "index: " << heap[index].Priority << endl;
                // cout << "parent: " << heap[parent].Priority << endl << endl;
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(Item heap[], int size, int index) {
    while (2 * index + 1 < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild].Priority > heap[largest].Priority) {
            largest = leftChild;
        }

        if (rightChild < size && heap[rightChild].Priority > heap[largest].Priority) {
            largest = rightChild;
        }

        if (largest != index) {
            // cout << "Swap" << endl;
            // cout << "index: " << heap[index] << endl;
            // cout << "parent: " << heap[largest] << endl << endl;
            swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void enqueue(Item heap[], int& size, string name, int priority, string code) {
    if (size < MAX_SIZE) {
        heap[size].Name = name;
        heap[size].Priority = priority;
        heap[size].Code = code;
        size++;
        heapifyUp(heap, size, size - 1);
    } else {
        std::cerr << "Priority queue is full.\n";
    }
}

void dequeue(Item heap[], int& size) {
    if (size > 0) {
        heap[0] = heap[--size];
        heapifyDown(heap, size, 0);
    } else {
        std::cerr << "Priority queue is empty.\n";
    }
}

bool isEmpty(int size) {
    return size == 0;
}

int main() {
    Item priorityQueue[MAX_SIZE];
    int size = 0;

    enqueue(priorityQueue, size, "GPU", 3, "G407");
    enqueue(priorityQueue, size, "CPU", 4, "C139");
    enqueue(priorityQueue, size, "Harddrive", 1, "S990");
    enqueue(priorityQueue, size, "Firmware", 2, "F1209");
    enqueue(priorityQueue, size, "Software", 5, "S221");

    cout << "Based on priority" << endl;
    while (!isEmpty(size)) {
        cout << "Item: " << priorityQueue[0].Name << ", "; // Print the front without dequeuing
        cout << "Priority: " << priorityQueue[0].Priority << ", ";
        cout << "Code: " << priorityQueue[0].Code << endl;
        dequeue(priorityQueue, size);
    }

    return 0;
}