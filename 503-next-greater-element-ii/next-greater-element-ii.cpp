class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);

        for(int i = 2*n-1; i>=0; i--){
            while(!s.empty() && nums[s.top()] <= nums[i%n]){
                s.pop();
            }
            ans[i%n] = s.empty()? -1 : nums[s.top()];
            s.push(i%n); 
        }
        return ans;
    }
};