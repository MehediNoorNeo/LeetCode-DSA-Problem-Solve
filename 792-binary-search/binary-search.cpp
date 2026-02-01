class Solution {
public:
    int binarySearch(vector<int> &vec, int start, int end, int target){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target == vec[mid]){
                return mid;
            }
            else if(target < vec[mid]){
                return binarySearch(vec, start, mid-1, target);
            }
            else{
                return binarySearch(vec, mid+1, end, target);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch (nums, 0, nums.size()-1, target);
    }
};