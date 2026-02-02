class Solution {
public:
    void getPermutation(vector<int> &nums, int idx, vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]); // idx => the position where taking choiche
            getPermutation(nums, idx+1, ans);
            // Backtracking
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutation(nums, 0, ans);
        return ans;
    }
};