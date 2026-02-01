class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> sa;
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        int count = 0;
        for(int j=0; j<n; j++){
            if(prefixSum[j] == k){
                count++;
            }
            // Searching first prefix sum to find subArray sum which is equal to k
            int firstPrifixSum = prefixSum[j] - k;
            if(sa.find(firstPrifixSum) != sa.end()){
                count += sa[firstPrifixSum];
            }
            sa[prefixSum[j]]++;
        }
        return count;
    }
};