#include "header.h"

using namespace std;

int main() {
    LinkedListQueue q;
    int cap;
    cout << "init queue : "; cin >> cap;
    q.init(cap);
    q.enqueue(10);
    if (q.isEmpty()) {
        cout << "Empty" << endl;
    } else {
        cout << "Not Empty" << endl;
    }
    int x = q.dequeue();
    cout << x << endl;
    if (q.isEmpty()) {
        cout << "Empty";
    } else {
        cout << "Not Empty";
    }
    return 0;
}