/*
    Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
    find the area of largest rectangle in the histogram.

    Example:
    Input: [2,1,5,6,2,3]
    Output: 10
*/

/*
    Solution - 1
    TC: O(n^2)
    SC: O(1)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int max_area = 0;

        for(int i=0; i<heights.size(); ++i) {
            // sweep left
            int width = 1;
            int j;
            for(j=i-1; j>=0 && heights[j] >= heights[i]; --j);

            width += i-1 - j;

            for(j=i+1; j<heights.size() && heights[j] >= heights[i]; ++j);

            width += j - i-1;

            max_area = max(max_area, heights[i] * width);
        }      

        return max_area;
        
    }
};

/*
    Solution - 2
    TC: O(n)
    SC: O(n)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsleft = next_smaller_left(heights), nsright = next_smaller_right(heights);
        int max_area = 0;

        for(int i=0; i<heights.size(); ++i) {
            int width = 1 + (i-1 - nsleft[i]) + (nsright[i] - i-1);
            max_area = max(max_area, heights[i] * width);
        }

        return max_area;
    }

    vector<int> next_smaller_left(vector<int> &a) {
        vector<int> res(a.size(), -1);
        stack<pair<int, int>> stk;
        for(int i=a.size()-1; i>=0; --i) {
            while(!stk.empty() && stk.top().second > a[i]) {
                res[stk.top().first] = i;
                stk.pop();
            }
            stk.push({i, a[i]});
        }
        return res;
    }

    vector<int> next_smaller_right(vector<int> &a) {
        vector<int> res(a.size(), a.size());
        stack<pair<int, int>> stk;
        for(int i=0; i<a.size(); ++i) {
            while(!stk.empty() && stk.top().second > a[i]) {
                res[stk.top().first] = i;
                stk.pop();
            }
            stk.push({i, a[i]});
        }
        return res;
    }
};