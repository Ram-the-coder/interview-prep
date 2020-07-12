/********** Implement a stack using two queues **********/

/* Solution

    Method 1
        - In this method the queue front represents the stack top
        Push Time Complexity: O(n)
            - Add new data to q2. Pop all from q1 and add it to q2. Swap q1, q2
        Pop Time Complexity: O(1)
            - Pop q1

    Method 2
        - In this method the queue rear represents the stack top
        Push Time Complexity: O(1)
            - Push to q1
        Pop Time Complexity: O(n)
            - Pop all from q1 and push it to q2 till q1.size() reaches 1
            - Pop the last element and return it
            - Swap q1, q2

    Method 1 is implemented below
*/

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
    q2.push(x);
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    
    swap(q1, q2);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.empty()) return -1;
    int data = q1.front();
    q1.pop();
    return data;
}




/********** Implement a stack using a single queue **********/

// Solution
// Push Time Complexity: O(n)
// Pop Time Complexity: O(1)

class Stack 
{ 
    queue<int>q; 
public: 
    void push(int val); 
    void pop(); 
    int top(); 
    bool empty(); 
}; 
  
// Push operation 
void Stack::push(int val) 
{ 
    //  Get previous size of queue 
    int s = q.size(); 
  
    // Push current element 
    q.push(val); 
  
    // Pop (or Dequeue) all previous 
    // elements and put them after current 
    // element 
    for (int i=0; i<s; i++) 
    { 
        // this will add front element into 
        // rear of queue 
        q.push(q.front()); 
  
        // this will delete front element 
        q.pop(); 
    } 
} 
  
// Removes the top element 
void Stack::pop() 
{ 
    if (q.empty()) 
        cout << "No elements\n"; 
    else
        q.pop(); 
} 
  
// Returns top of stack 
int  Stack::top() 
{ 
    return (q.empty())? -1 : q.front(); 
} 
  
// Returns true if Stack is empty else false 
bool Stack::empty() 
{ 
    return (q.empty()); 
} 