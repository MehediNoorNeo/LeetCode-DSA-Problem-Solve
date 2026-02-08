class Solution {
public:
    bool isPalindrome(string str){
        int start = 0;
        int end = str.length()-1;
        while(start <= end){
            if(str[start] != str[end]){
                return false;
            }
            start++; end--;
        }
        return true;
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