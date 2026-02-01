class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rstart = 0, rend = row-1;
        while(rstart <= rend){
            int rmid = rstart + (rend - rstart)/2;
            if(matrix[rmid][0] <= target && target <= matrix[rmid][col-1]){
                int cstart = 0;
                int cend = col -1;
                while(cstart <= cend){
                    int cmid = cstart + (cend - cstart)/2;
                    if(matrix[rmid][cmid] == target){
                        return true;
                    }
                    else if(target > matrix[rmid][cmid]){
                        cstart = cmid + 1;
                    }
                    else{
                        cend = cmid - 1;
                    }
                }
                return false; // if target not exist in the row
            }
            else if(target > matrix[rmid][col-1]){
                rstart = rmid + 1;
            }
            else{
                rend = rmid - 1;
            }
        }
        return false;
    }
};