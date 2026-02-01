class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int area = 0;

        while(left < right){
            int width = right - left;
            int tall = min(height[left], height[right]);
            area = max(area, width*tall);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};