class Solution {
public:
    int search(vector<int>& vec, int target) {
        int start = 0;
        int end = vec.size()-1;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(target == vec[mid]){
                return mid;
            }
            if(vec[start] <= vec[mid]){ // left sorted
                if(vec[start] <= target && target <= vec[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            else{ // right sorted
                if(vec[mid] <= target && target <= vec[end]){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};