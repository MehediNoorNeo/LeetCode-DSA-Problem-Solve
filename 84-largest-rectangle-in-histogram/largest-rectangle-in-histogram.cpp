class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> s;
        vector<int> rsn(n);
        vector<int> lsn(n);

        //find right small nearest
        for(int i = n-1; i >=0 ; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            rsn[i] = s.empty()? n : s.top();
            s.push(i);
        }
        // clear stack
        while(!s.empty()){
            s.pop();
        }
        //find left small nearest
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            lsn[i] = s.empty()? -1 : s.top();
            s.push(i);
        }
        // calculate area
        for(int i = 0; i < n; i++){
            int width = rsn[i]-lsn[i]-1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans;
    }
};