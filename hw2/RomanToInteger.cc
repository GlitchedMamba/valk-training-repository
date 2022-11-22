class Solution {
public:
    int romanToInt(string s) {
        /*
        I = 1;
         IV = 4;
         V = 5;
         IX = 9;
         X = 10;
         XL = 40;
         L = 50;
         XC = 90;
         C = 100;
         CD = 400;
         D = 500;
         CM = 900;
         M = 1000;
         */
        int prev = 0;
        int curr = 0;
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case 'I':
                    curr = 1;
                    break; 
                case 'V':
                    curr = 5;
                    break;
                case 'X':
                    curr = 10;
                    break;;
                case 'L':
                    curr = 50;
                    break;
                case 'C':
                    curr = 100;
                    break;
                case 'D':
                    curr = 500;
                    break;
                case 'M':
                    curr = 1000;
                    break; 
            }
            num += curr;
            if (prev < curr) {
                num -= 2*prev;
            }
            prev = curr;
        }
        
        
        return num;
    }
};
