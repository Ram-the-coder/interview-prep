/*
    The task is to design and implement methods of an LRU cache. The class has two methods get() and set() which are defined as follows.

    get(x)   :  Returns the value of the key x if the key exists in the cache otherwise returns -1.
    set(x,y) :  inserts the value if the key x is not already present. 
                If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.

    In the constructor of the class the size of the cache should be intitialized.


    Expected Time Complexity: O(1) for both get() and set().
    Expected Auxiliary Space: O(1) for both get() and set(). (though, you may use extra space for cache storage and implementation purposes).
*/


/**************************************** Solution 1 - Using self defined queue ********************************************************************************/


/**************************************** DLL ****************************************/
class DLL_Node {
public:
    int data, key;
    DLL_Node *next, *prev;

    DLL_Node(int val, int k) : data(val), key(k), next(NULL), prev(NULL) {}
};

class Queue_Using_DLL {
    DLL_Node *front, *back;
    int max_size, elements_count;

public:

    Queue_Using_DLL() : front(NULL), back(NULL), max_size(INT_MAX), elements_count(0) {}
    Queue_Using_DLL(int n) : front(NULL), back(NULL), max_size(n), elements_count(0) {}

    DLL_Node* enqueue(int data, int key) {
        if(elements_count == max_size) return NULL; // queue full

        DLL_Node *newEntry = new DLL_Node(data, key);
        if(front == NULL) front = back = newEntry;
        else {
            back->next = newEntry;
            newEntry->prev = back;
            back = newEntry;
        }

        ++elements_count;
        return back;
    }

    int dequeue() {
        if(elements_count == 0) return -1; // queue empty

        DLL_Node *to_be_deleted = front;
        int key = to_be_deleted->key;

        if(front == back) front = back = NULL;
        else {
            front = front->next;
            front->prev = NULL;
        }

        delete(to_be_deleted);
        --elements_count;

        return key;
    }
    
    int size() {
        return elements_count;
    }
    
    void move_back(DLL_Node *node) {
        if(back == node) return;
        
        if(!node->prev) {
            front = node->next;
            node->next->prev = NULL;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;    
        }
        
        back->next = node;
        node->prev = back;
        back = node;
    }
};

/**************************************** LRU Cache ****************************************/

class LRUCache
{
private:
    Queue_Using_DLL* q;
    unordered_map<int, DLL_Node*> lookup;
    int max_cap;

public:
    LRUCache(int cap)
    {
        // constructor for cache
        q = new Queue_Using_DLL(cap);
        lookup.reserve(cap);
        max_cap = cap;
    }
    
    int get(int key)
    {
        // this function should return value corresponding to key
        if(lookup.find(key) != lookup.end()) {
            q->move_back(lookup[key]);
            return lookup[key]->data;
        }
        
        return -1;
    }
    
    void set(int key, int value)
    {
        // storing key, value pair
        if(lookup.find(key) != lookup.end()) {
            lookup[key]->data = value;
            q->move_back(lookup[key]);
            return;
        }
        
        if(q->size() == max_cap) lookup.erase(q->dequeue());
        lookup[key] = q->enqueue(value, key);
    }
};


/**************************************** Solution 2 - Using STL list ********************************************************************************/
class LRUCache
{
private:
    list<pair<int, int>> q;
    unordered_map<int, list<pair<int, int>>::iterator> lookup;
    int max_cap;

public:
    LRUCache(int cap)
    {
        // constructor for cache
        lookup.reserve(cap);
        max_cap = cap;
    }
    
    int get(int key)
    {
        // this function should return value corresponding to key
        if(lookup.find(key) != lookup.end()) {
            int value = (*lookup[key]).second;
            q.erase(lookup[key]);
            q.push_front({key, value});
            lookup[key] = q.begin();
            return value;
        }
        
        return -1;
    }
    
    void set(int key, int value)
    {
        // storing key, value pair
        if(lookup.find(key) != lookup.end()) {
            q.erase(lookup[key]);
            q.push_front({key, value});
            lookup[key] = q.begin();
            return;
        }
        
        if(q.size() == max_cap) {lookup.erase(q.back().first); q.pop_back();}
        q.push_front({key, value});
        lookup[key] = q.begin();
    }
};