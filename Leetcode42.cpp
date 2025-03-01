class Solution1 {
    public:
        int trap(vector<int>& height) {
            
            int size = height.size();
            // having the maxleft at every index
            vector<int>preMax(size, 0);
            preMax[0] = height[0];
            for( int i = 1; i < size; i++ ){
                preMax[i] = max(preMax[i-1], height[i]);
            }
            // having the rightmax at every index
            vector<int>sufMax(size, 0);
            sufMax[size-1] = height[size-1];
            for( int i = size-2; i >= 0; i-- ){
                sufMax[i] = max(sufMax[i+1], height[i]);
            }
            int trappedWater = 0;
            for( int i = 0; i < size; i++ ){
                int leftmax = preMax[i];
                int rightmax = sufMax[i];
                if(height[i] < leftmax && height[i] < rightmax){
                    trappedWater += min(leftmax, rightmax) - height[i];
                }
            }
            return trappedWater;
        }
    };
    
    
    
    class Solution {
    public:
        int trap(vector<int>& height) {
            
            int size = height.size();
            int trappedWater = 0;
            int leftMax = 0, rightMax = 0;
            int left = 0, right = size-1;
            while(left < right){
                if(height[left] <= height[right]){
                    if(height[left] < leftMax){
                        trappedWater += leftMax - height[left];
                    }
                    else{
                        leftMax = height[left];
                    }
                    left++;
                }
                else{
                    if(height[right] < rightMax){
                        trappedWater += rightMax - height[right];
                    }
                    else{
                        rightMax = height[right];
                    }
                    right--;
                }
            }
            return trappedWater;
        }
    };