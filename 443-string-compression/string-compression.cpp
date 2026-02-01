class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int i = 0;
        while( i < chars.size()){
            char anchor = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == anchor){
                count++; i++;
            }
            if(count > 1){
                s += anchor + to_string(count);

            }
            else{
                s += anchor;
            }
        }
        chars.clear();

        for(int j=0; j<s.length(); j++){
            chars.push_back(s[j]);
        }
        return chars.size();
    }
};