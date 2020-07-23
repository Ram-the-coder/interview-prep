/*
    Given an array of integers and a number K. 
    Find the count of distinct elements in every window of size K in the array.
*/

/*
    Solution
    Time Complexity: O(n)
    Space Complexity: min( O(MAX INTEGER VALUE), O(n), O(k) )
*/
vector <int> countDistinct (int A[], int n, int k)
{
    unordered_map<int, int> freq;
    freq.reserve(1e5);
    vector<int> res;
    int count = 0;
    for(int i=0; i<k && i<n; ++i) {
        if(!freq[A[i]]) ++count;
        freq[A[i]]++;
    }   
    
    res.push_back(count);
    
    for(int i=k; i<n; ++i) {
        freq[A[i-k]]--;
        if(!freq[A[i-k]]) --count;
        if(!freq[A[i]]) ++count;
        freq[A[i]]++;
        res.push_back(count);
    }
    
    return res;
}