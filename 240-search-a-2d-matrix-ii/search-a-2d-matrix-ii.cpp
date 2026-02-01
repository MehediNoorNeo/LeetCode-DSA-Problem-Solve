class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int c = col-1, r = 0;

        while(0 <= c && r <= row-1){
            if(target == matrix[r][c]){
                return true;
            }
            else if(target < matrix[r][c]){
                c--;
            }
            else{
                r++;
            }
        }
        return false;
    }
};