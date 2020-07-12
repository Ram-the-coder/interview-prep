/*
    Method 1 - Stack top is the queue front
    Push Time Complexity: O(n)
    Pop Time Complexity: O(1)
*/ 

/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
void StackQueue :: push(int x)
{
    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    s2.push(x);
    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    if(s1.empty()) return -1;
    int data = s1.top();
    s1.pop();
    return data;
}



/*
    Method 2 - Stack top is the queue rear (Optimized dequeue)
    Push Time Complexity: O(1)
    Pop Time Complexity: O(n)
    Amortized Time Complexity of Pop: O(1)
*/ 

/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
// Stack top is the queue rear
void StackQueue :: push(int x)
{
    s1.push(x);
}

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    if(s1.empty() && s2.empty()) return -1;
    if(s2.empty()) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int data = s2.top();
    s2.pop();
    return data;
}


/*
    Method 3 - Using a single user stack
    Push TC: O(1)
    Pop TC: O(n)
*/

struct Queue { 
    stack<int> s; 
  
    // Enqueue an item to the queue 
    void enQueue(int x) 
    { 
        s.push(x);
    } 
  
    // Dequeue an item from the queue 
    int deQueue() 
    { 
        if(s.empty()) return -1;

        int data = s.top();
        s.pop();

        if(s.empty()) return data;

        int top = deQueue();

        s.push(data);
        
        return top;
    } 
}; 