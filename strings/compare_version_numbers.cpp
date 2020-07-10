/*
    Compare two version numbers version1 and version2.
    If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

    You may assume that the version strings are non-empty and contain only digits and the . character.

    For instance, 2.5 is not "two and a half" or "half way to version three", 
    it is the fifth second-level revision of the second first-level revision.

    Note:
    1. Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
    2. Version strings do not start or end with dots, and they will not be two consecutive dots
*/


/*
    Solution
    Time Complexity: O(n + m)
    Space Complexity: O(1)
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int v1 = 0, v2 = 0;
        while(i < version1.length() || j < version2.length()) {
            
            while(i < version1.length() && version1[i] != '.') {
                v1 = v1*10 + version1[i++] - '0';
            }
            i++;
            
            while(j < version2.length() && version2[j] != '.') {
                v2 = v2*10 + version2[j++] - '0';
            }
            j++;           
            
            
            if(v1 == v2) {
                v1 = v2 = 0;
                continue;
            }
            
            return v1 < v2 ? -1 : 1;
        }

        return 0;
    }
};