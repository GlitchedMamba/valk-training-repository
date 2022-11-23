class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int requests = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (x == y) {
                    continue;
                }
                if (ages[y] <= 0.5 * ages[x] + 7 || ages[y] > ages[x] || (ages[y] > 100 && ages[x] < 100))  {
                    continue;
                }
                requests++;
            }
        }
        return requests;
    }
};
