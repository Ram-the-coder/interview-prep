/*
	To find the number of trailing zeroes in n!

	Solution Logic: The number of trailing zeroes is equal to the number of pairs of 2 and 5s there exists as
	factors of n!

	Since every other number has a factor of 2, the limiting factor is the number of 5s.

	Key point to note is that some numbers have more than one 5 as a factor (e.g. 25).

	There the total number of trailer zeroes = the total number of times 5 is a factor in n!

*/

class Solution {
public:
    int trailingZeroes(int n) {
        int num = 0;
        while(n) {
            num += floor(n/5); // Number of numbers divisible by 5 from 1 to n is n/5
            n /= 5; // So that next time you can find the number of numbers divisible by 25 = n/25 = (n/5)/5
        }
        return num;
    }
};