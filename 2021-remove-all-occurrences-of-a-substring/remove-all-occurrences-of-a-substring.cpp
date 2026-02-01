class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos;
        while(0 < s.length() && s.find(part) < s.length()){
            pos = s.find(part);
            s.erase(pos, part.length()); 
        }
        return s;
    }
};