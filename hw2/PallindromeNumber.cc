class Solution {
public:
    bool isPalindrome(int x) {
        char num[20];
        sprintf(num, "%d", x);
        int n = strlen(num);
        for (int i = 0; i<n/2; i++) {
            if (num[i] != num[n-1-i]) {
                return false;
            }
        }
        return true;
    }
};
