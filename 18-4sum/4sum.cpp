class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                long long newTarget = (long long)target -((long long)nums[i] + (long long)nums[j]);
                int start = j+1, end = n-1;
                while(start < end){
                    long long sum = (long long)nums[start] + (long long)nums[end];
                    if(newTarget == sum){
                        vector<int> trip = {nums[i], nums[j], nums[start], nums[end]};
                        ans.push_back(trip);
                        start++; end--;
                        while(start < end && nums[start] == nums[start-1]){
                        start++;
                        }
                    }
                    else if(newTarget < sum){
                    end--;
                    }
                    else{
                        start++;
                    }
                }
            }
        }
        return ans;
    }
};