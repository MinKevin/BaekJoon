//https://leetcode.com/problems/jump-game/submissions/876694314/
//Solution1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;

        int dp[10000];
        fill(&dp[0], &dp[10000], 0);
        for (int i = nums.size() - 2; i >= 0; i--) {
            int length = (nums.size() - 1) - i;
            if (nums[i] >= length) {
                dp[i] = 1;
            }
            else {
                for (int j = 1; j <= nums[i]; j++) {
                    if (dp[i + j] == 1) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};

//Solution2
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;

        int index = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            index = max(i + nums[i], index);
            if (index == i)
                break;
        }
        return index >= nums.size() - 1;
    }
};