class Solution {
public:
    set<vector<int>> s;
    void getAllCombination(vector<int>& arr, int idx, int tar,  vector<int> &combin, vector<vector<int>> &ans){
        // base case
        if(idx == arr.size() || tar < 0){
            return;
        }
        if(tar == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }
        combin.push_back(arr[idx]);
        // inclusion
        getAllCombination(arr, idx+1, tar-arr[idx], combin, ans);
        // multiple
        getAllCombination(arr, idx, tar-arr[idx], combin, ans);

        combin.pop_back();
        // exclusion
        getAllCombination(arr, idx+1, tar, combin, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<int> combin;
        vector<vector<int>> ans;

        getAllCombination(arr, 0, tar, combin, ans);
        return ans;
    }
};