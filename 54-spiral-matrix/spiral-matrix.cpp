class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size(), col = matrix[0].size();
        
        int top = 0, bottom = row - 1, left = 0, right = col-1;
        while (top <= bottom && left <= right){
            // top
            for(int i=left; i <= right; i++ ){
                result.push_back(matrix[top][i]);
            }
            top++;
            // right
            for(int i=top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;
            // bottom
            if(top <= bottom){
                for(int i=right; i >= left; i--){
                    result.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            // left
            if(left <= right){
                for(int i=bottom; i >= top; i--){
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
        } 
        return result;
    }
};