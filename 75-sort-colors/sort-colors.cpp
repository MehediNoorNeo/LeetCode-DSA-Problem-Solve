class Solution {
public:
    void sortColors(vector<int>& vec) {
        int n = vec.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while(mid <= high){
            if(vec[mid] == 0){
                swap(vec[low], vec[mid]);
                low++;
                mid++;
            }
            else if(vec[mid] == 1){
                mid++;
            }
            else{  // vec[mid] == 2
                swap(vec[mid], vec[high]);
                high--;
            }
        }
    }
};