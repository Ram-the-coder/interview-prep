/*
    Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
    You can only see the k numbers in the window. Each time the sliding window moves right by one position. 
    Return the max sliding window.
    
    Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
    Output: [3,3,5,5,6,7] 
*/

/*
    Solution 1
    TC: O(k*(n-k+1)) in worst case, O(n) in best case
    SC: O(1)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int index_of_max = max_element(a.begin(), a.begin()+k) - a.begin();
        vector<int> res;
        res.pb(a[index_of_max]);

        for(int i=k; i<a.size(); ++i) {
            if(a[i] > a[index_of_max]) index_of_max = i; 
            
            if(index_of_max <= i-k) index_of_max = max_element(a.begin()+i-k+1, a.begin()+i+1) - a.begin();   

            res.pb(a[index_of_max]);
        }

        return res;
    }
};


/*
    Solution 2
    TC: O(n)
    SC: O(k)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> q; // stores index

        // The queue is of max size k
        // The queue should be in descending order - if in the window a[i] is greater than all elements before it
        // then for all the windows that include a[i], the elements before it cannot be max
        // so no need to store those elements that are less than the element to the right
        // queue.front() indicates the largest element in the current window

        for(int i=0; i<k; ++i) {
            while(!q.empty() && a[q.back()] <= a[i]) q.pop_back();
            q.push_back(i);
        }      

        vector<int> res;
        res.push_back(a[q.front()]);

        for(int i=k; i<a.size(); ++i) {
            if(!q.empty() && q.front() <= i-k) q.pop_front();
            while(!q.empty() && a[q.back()] <= a[i]) q.pop_back();
            q.push_back(i);
            res.push_back(a[q.front()]);
        }

        return res;
    }
};