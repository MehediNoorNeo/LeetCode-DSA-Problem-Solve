class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size());

        for(int i = nums.size()-1; i>=0; i--){
            while(!s.empty() && s.top() <= nums[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
                s.push(nums[i]);
                for(int j=0; j<i; j++){
                    if(nums[j] > nums[i]){
                        ans[i] = nums[j];
                        break;
                    }
                }
            }
            else{
                ans[i] = s.top();
                s.push(nums[i]);
            }
        }
        return ans;
    }
};