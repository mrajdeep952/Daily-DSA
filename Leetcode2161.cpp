class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
    
            int cnt1 = 0;
            int cnt2 = 0;
            int cnt3 = 0;
            for( int i = 0; i < nums.size(); i++ ){
                if(nums[i] < pivot) cnt1++;
                else if(nums[i] == pivot) cnt2++;
                else cnt3++;
            }
            int idx1 = 0;
            int idx2 = idx1 + cnt1;
            int idx3 = idx2 + cnt2;
            vector<int>result(nums.size(), 0);
            int cnt0 = 0;
            for( int i = 0; i < nums.size(); i++ ){
                if(nums[i] < pivot){
                    result[idx1] = nums[i];
                    idx1++;
                }
                else if(nums[i] == pivot){
                    result[idx2] = nums[i];
                    idx2++;
                }
                else{
                    result[idx3] = nums[i];
                    idx3++;
                }
            }
            return result;
        }
    };