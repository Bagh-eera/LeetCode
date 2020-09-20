class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        
        int left = 0, right = height.size()-1;
        int total = 0;
        int left_max = height[left], right_max = height[right];
        
        while(left < right){
            if(height[left] < height[right]){
                if(left_max < height[left]){
                    left_max = height[left];
                }else{
                    total += left_max-height[left];
                }
                left++;
            }else{
                if(right_max < height[right]){
                    right_max = height[right];
                }else{
                    total += right_max - height[right];
                }
                right--;
            }
        }
        return total;
    }
};
