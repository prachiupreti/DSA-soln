class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<int>& curr, int i) {

        if (i >= nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        backtrack(nums, curr, i + 1);
        curr.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        backtrack(nums, curr, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> curr;
        backtrack(nums, curr, 0);

        return ans;
    }
};