class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /***** Step 1: Find the intersection point of tortoise and hare *****/
        int hare=0, tortoise=0;
        do {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        } while(hare != tortoise);

        /***** Step 2: Find the entry point of the loop *****/

        tortoise = 0; // Bring tortise to start and keep hare at the intersectin pt.
        
        do {
            hare = nums[hare];
            tortoise = nums[tortoise];
        } while(hare != tortoise);
        
        return hare;
    }
};

/*
The list will always have a duplicate element
We can consider that the indices 1..n also denote the presence of element 
Starting from index 0, if we keep following the sequence
nums[0] -> nums[nums[0]] -> nums[nums[nums[0]]].....
Then we'll be creating a link of distinct indices
When the second occurence of the duplicate element comes,
that'll point to an index in the existing link
which means that it'll form a loop
The duplicate element will be the element that'll be at the entry of the loop

To find that, we'll use floyd's tortoise and hare algorithm

***** Step 1: Find the intersection point of tortoise and hare *****

The key point to note here is that the index 0 cannot be a part of the loop as all elements are greater than 0
F - The distance from index 0 to the loop's entry point
a - The distance between the loop's entry point and the intersection of hare and tortoise
C - The number of nodes in the loop
n - some integer
2(F+a) = F + nC + a -> 2(distance covered by tortoise) = distance covered by hare
=> F + a = nC



***** Step 2: Find the entry point of the loop *****

Bring tortoise to index 0 and keep hare at a.
With same speed move hare and tortoise, wherever they intersect is the loop's entry point
This follows from the previous equation F + a = nC
i.e. on taking F steps from a, the hare will reach the entry point
but we don't know F
but by definition we know that F is the distance of entry point from index 0
So we'll just let the hare and tortoise move at same speed and intersect
*/