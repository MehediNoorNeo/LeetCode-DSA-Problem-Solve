class Solution {
public:
    bool isAlphanumeric(char ch){
        if(('0' <= ch && ch <= '9') || ('a' <= tolower(ch) && tolower(ch) <= 'z')){
            return true;
        }
        else{
            return false;
        }
    }
    bool isPalindrome(string s) {
        int start = 0, end = s.length()-1;
        
        while(start < end){
            if(!isAlphanumeric(s[start])){
                start++; 
                continue;
            }
            if(!isAlphanumeric(s[end])){
                end--; 
                continue;
            } 
            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }
        } 
        return true;
    }
};