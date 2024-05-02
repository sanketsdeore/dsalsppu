#include <iostream>
#include <string>
using namespace std;

enum Type {
    serious, non_serious, general
};

struct Patient {
    string name;
    Type type;
};

class PriorityQ {
    Patient patients[5];
    int front, rear, size;
    
    public:
    PriorityQ () {
        front = -1;
        rear = -1;
        size = 5;
    }
    bool isEmpty () {
        return (front == -1);
    }
    bool isFull () {
        return (rear == size - 1);
    }
    
    void enqueue (string name, Type type) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
        }
        
        Patient patient;
        patient.name = name;
        patient.type = type;
        
        patients [++ rear] = patient;
        
        if (front == -1) {
            front = 0;
        }
        
        for (int i = rear; i > front; i --) {
            if (patients[i].type < patients[i - 1].type) {
                swap (patients[i], patients[i - 1]);
            } else {
                break;
            }
        }
    }
    
    void dequeue () {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        }
        
        cout << "Dequeued " << patients[front].name << endl;
        
        if (front == rear) {
            front = rear = -1;
        } else {
            front ++;
        }
    }
    
    void display () {
        cout << "Discharge Order: " << endl;
        for (int i = front; i <= rear; i ++) {
            cout << patients[i].name << endl;
        }
    }
};

int main() {
    PriorityQ p;
    string name;
    int type, choice;
    
    while (choice != 4) {
        cout << "\n***Menu***" << endl;
        cout << "1. Enqueue Patient." << endl;
        cout << "2. Dequeue Patient." << endl;
        cout << "3. Display Discharge Order." << endl;
        cout << "4. Exit." << endl;
        
        cout << "\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\nEnter name: ";
                cin >> name;
                cout << "\nEnter type: ";
                cin >> type;
                p.enqueue (name, static_cast<Type>(type));
                break;
            case 2:
                p.dequeue();
                break;
            case 3:
                p.display();
                break;
            case 4:
                cout << "\nThank You!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
