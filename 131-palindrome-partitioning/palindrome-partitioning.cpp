class Solution {
public:
    bool isPalindrome(string str){
        string str2 = str;
        reverse(str2.begin(), str2.end());
        return str2 == str;
    }
    void getAllParts(string s,  vector<vector<string>> &ans, vector<string> &partition){
        //base case
        if(s.length() == 0){
            ans.push_back(partition);
            return;
        }
        for(int i=0; i<s.length(); i++){
            string part = s.substr(0, i+1);
            if(isPalindrome(part)){
                partition.push_back(part);
                getAllParts(s.substr(i+1), ans, partition);
                //backtracking
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        getAllParts(s, ans, partition);
        return ans;
    }
};