class Solution {
    private:
        bool isPossible(vector<int>& ranks, int cars, long long target){
    
            long long cnt = 0;
            for( int i = 0; i < ranks.size(); i++ ){
                long long currCnt = 1;
                while((ranks[i]*currCnt*currCnt) <= target){
                    currCnt++;
                }
                cnt += currCnt-1;
                if(cnt >= cars) return true;
            }
            return false;
        }
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            
            long long start = 0;
            long long end = *max_element(ranks.begin(), ranks.end())*(long long)cars*cars;
            long long res = 0;
    
            while(start <= end){
                long long mid = start + (end - start)/2;
                // cout << mid << endl;
                if(isPossible(ranks, cars, mid)){
                    // cout << "hit " << mid << endl;
                    res = mid;
                    end = mid - 1;
                }
                else start = mid + 1;
            }
            return res;
        }
    };