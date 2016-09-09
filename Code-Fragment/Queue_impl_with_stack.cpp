// Implement Queue with stack

/*
 * Implement the following operations of a queue using stacks.
 *
 *  push(x) -- Push element x to the back of queue.
 *  pop() -- Removes the element from in front of queue.
 *  peek() -- Get the front element.
 *  empty() -- Return whether the queue is empty.
 *
 */


/*
 * // For test
 * #include <iostream>
 * #include <stack>
 * using namespace std;
 */

template <typename T>
class Queue {
    stack<T> s1;
    stack<T> s2;
    
    void refill_stack(){
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
public:
    // Push element x to the back of queue.
    void push(T x) {
        s1.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        if (s2.empty())
            refill_stack();
        s2.pop();
    }
    
    // Get the front element.
    T peek(void) {
        if (s2.empty())
            refill_stack();
        return s2.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return (s1.empty() && s2.empty());
    }
    
    // Return the size of the queue
    T size(void){
        return (s1.size() + s2.size());
    }
};


/*
int main(){
    Queue<double> q;
    q.push(1.1);
    q.push(2.0);
    q.push(3.1);
    cout << "top: " << q.peek() << endl;
    q.pop();
    cout << "top: " << q.peek() << endl;
    cout << "size: " << q.size() << endl;
    return 0;
    
}
*/