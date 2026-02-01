class Solution {
public:
    void allSubsets(vector<int> &arr, vector<int> &ans, int i, vector<vector<int>> &allSets){
        if(i == arr.size()){
            allSets.push_back(ans);
            return;
        }
        // include
        ans.push_back(arr[i]); 
        allSubsets(arr, ans, i+1, allSets); // Forwarding

        // exclude
        ans.pop_back(); // Backtracking
        
        int idx = i+1;
        while(idx < arr.size() && arr[idx] == arr[idx-1]) idx++;
        allSubsets(arr, ans, idx, allSets);
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<vector<int>> allSets;
        allSubsets(nums, ans, 0, allSets);
        return allSets;
    }
};