#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map <char, int> freq, winFreq;
        // frequence of s1
        for(char c : s1){
            freq[c]++;
        }

        int k = s1.length();
        // first window
        for(int i=0; i<k; i++){
            winFreq[s2[i]]++;
        }
        if(freq == winFreq) return true;

        char addChar, remvChar;
        for(int i=k; i<s2.length(); i++){
            addChar = s2[i];
            remvChar = s2[i-k];
            
            winFreq[addChar]++;
            winFreq[remvChar]--;

            if(winFreq[remvChar] == 0){
                winFreq.erase(remvChar);
            }
            if(freq == winFreq) return true;
        }
        return false;
    }
};
