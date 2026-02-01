class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        if(nums.size() == 1){
            return nums[start];
        }
        if(nums[start] != nums[start + 1]){
            return nums[start];
        }
        if(nums[end-1] != nums[end]){
            return nums[end];
        }
        while(start <= end){ 
            int mid = start + (end-start)/2;
            
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            if(mid % 2 == 0){
                if(nums[mid-1] == nums[mid]){
                    end = mid - 2;
                }
                else{
                    start = mid + 2;
                }
            }
            else{
                if(nums[mid-1] == nums[mid]){
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