class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, first = 0;

        do{
            slow = nums[slow]; // +1
            first = nums[nums[first]]; // +2
        }while(slow != first);

        slow = 0;
        while(slow != first){
            slow = nums[slow]; // +1
            first = nums[first]; // +1
        }
        return slow;
    }
};