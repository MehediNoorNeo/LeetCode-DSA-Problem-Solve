class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int piv = -1;
        int n = nums.size();
        // searching pivot integer
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                piv = i;
                break;
            }
        }
        // searchig lowest greater value of pivot
        for(int i = n-1; i > piv; i--){
                if(piv != -1){
                    if(nums[i] > nums[piv]){
                    swap(nums[i], nums[piv]);
                    break;
                }
            }
        }
        // reversing after pivot elements
        // reverse(nums.begin() + piv + 1, nums.end());
        int start = piv + 1, end = n-1;
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
        
    }
};