class Solution {
public:
    bool isValidStep(int r1, int c1, int r2, int c2){
        int dr = abs(r1 - r2);
        int dc = abs(c1 - c2);
        if((dr==2 && dc==1) || (dr==1 && dc==2)){
            return true;
        }
        return false;
    }
    bool tour(int k, int n, vector<pair<int, int>> &pos){
        if(k == (n*n)-1){
            return true;
        }
        auto [r1, c1] = pos[k];
        auto [r2, c2] = pos[k+1];
        if(!isValidStep(r1, c1, r2, c2)){
            return false;
        }
        return tour(k+1, n, pos);
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> pos(n*n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                pos[grid[i][j]] = {i, j};
            }
        }
        if(pos[0] != make_pair(0, 0)){
            return false;
        }
        return tour(0, n, pos);
    }
};