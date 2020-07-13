/*
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

    /**
    * Your MinStack object will be instantiated and called as such:
    * MinStack* obj = new MinStack();
    * obj->push(x);
    * obj->pop();
    * int param_3 = obj->top();
    * int param_4 = obj->getMin();
    */
*/


/*
    Solution 1 - Using 2 stacks
    TC: O(1)
    SC: O(n)
*/

class MinStack {
    stack<int> min, all;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        all.push(x);
        if(min.empty() || min.top() >= x) min.push(x);
    }
    
    void pop() {
        if(min.top() == all.top()) min.pop();
        all.pop();
    }
    
    int top() {
        return all.top();
    }
    
    int getMin() {
        return min.top();
    }
};


/*
    Solution 2 - Using single stack
    TC: O(1)
    SC: O(n)
*/


 class MinStack {
    stack<pair<int, int>> stk;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(stk.empty()) stk.push({x, x});
        else stk.push({x, min(x, stk.top().second)});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};