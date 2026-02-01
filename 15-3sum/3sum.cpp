class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int start = i+1, end = n-1;
            while(start < end){
                int sum = nums[start] + nums[end];
                if(target == sum){
                    vector<int> trip = {nums[i], nums[start], nums[end]};
                    ans.push_back(trip);
                    start++; end--;
                    while(start < end && nums[start] == nums[start-1]){
                        start++;
                    }
                }
                else if(target < sum){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return ans;
    }
};