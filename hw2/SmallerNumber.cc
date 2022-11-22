class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int greater = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] > nums[j]) {
                    greater++;
                }
            }
            result[i] = greater;
        }
        return result;
    }
};
