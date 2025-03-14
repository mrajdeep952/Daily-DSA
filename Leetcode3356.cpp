class Solution {
    private:
        bool canBeTransformed(vector<int>& nums, vector<vector<int>>& queries, int k){
    
            vector<int>diffArr(nums.size()+1, 0);
            for( int i = 0; i <= k; i++ ){
                diffArr[queries[i][0]] -= queries[i][2];
                diffArr[queries[i][1]+1] += queries[i][2];
            }
            int prev = 0;
            for( int i = 0; i < nums.size(); i++ ){
                int diff = diffArr[i];
                diffArr[i] += nums[i] + prev;
                prev += diff;
                if(diffArr[i] > 0) return false;
            }
            return true;
        }
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            
            int maxElement = *max_element(nums.begin(), nums.end());
            if(!maxElement) return 0;
    
            int start = 0;
            int end = queries.size()-1;
            int minValue = -1;
    
            while(start <= end){
                int mid = start + (end-start)/2;
                if(canBeTransformed(nums, queries, mid)){
                    minValue = mid+1;
                    end = mid - 1;
                }
                else start = mid + 1;
            }
            return minValue;
        }
    };