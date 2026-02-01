class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m+n-1, i= m-1, j=n-1;
        while(0 <= i && j >= 0){
            if(nums2[j] > nums1[i]){
                nums1[idx] = nums2[j];
                idx--; j--;
            }
            else{
                nums1[idx] = nums1[i];
                idx--; i--;
            }
        }
        while(0 <= j){
            nums1[idx] = nums2[j];
                idx--; j--;
        }
    }
};