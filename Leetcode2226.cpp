class Solution {
    private:
        bool canBeAlloted(vector<int>& candies, long long k, int target){
    
            long long cnt = 0;
            for( int i = 0; i < candies.size(); i++ ){
                if(candies[i] >= target){
                    cnt += candies[i] / target;
                }
            }
            if(cnt >= k) return true;
            return false;
        }
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            
            int start = 1;
            int end = *max_element(candies.begin(), candies.end());
            int res = 0;
    
            while(start <= end){
                int mid = start + (end-start)/2;
                if(canBeAlloted(candies, k, mid)){
                    res = mid;
                    start = mid + 1;
                }
                else end = mid - 1;
            }
            return res;
        }
    };