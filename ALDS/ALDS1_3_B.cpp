//Queue
#include <iostream>

using namespace std;

const int MAX_PROCESS = 100000;

struct process{
    char name[10];
    int time;
};

class Queue {
public:
    Queue();
    void enqueue(process x);
    process dequeue();
    bool isEmpty();

private:
    process data[MAX_PROCESS];
    int head;
    int tail;
};

Queue::Queue() {
    head = 0;
    tail = 0;
}

void Queue::enqueue(process x) {
    data[tail] = x;
    tail++;
    if(tail == MAX_PROCESS) tail = 0;
}

process Queue::dequeue() {
    process x = data[head];
    head++;
    if(head == MAX_PROCESS) head = 0;
    return x;
}

bool Queue::isEmpty() {
    return head == tail;
}


int main() {
    Queue Q;

    int n, q;
    process x;
    cin >> n;
    cin >> q;
    for(int i = 0; i < n; i++) {
        cin >> x.name;
        cin >> x.time;
        Q.enqueue(x);
    }

    int t = 0;
    while(!Q.isEmpty()) {
        x = Q.dequeue();
        if(x.time > q) {
            x.time -= q;
            Q.enqueue(x);
            t += q;
        }
        else {
            t += x.time;
            cout << x.name << ' ' << t << endl;
        }
    }
}
