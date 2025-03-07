class Solution {
    private:
        void SieveOfEratosthenes(int n, vector<bool>& isPrime){
    
            isPrime[0] = isPrime[1] = false;
            for( int i = 2; i*i <= n; i++ ){
                if(isPrime[i] == true){
                    for( int j = i*i; j <= n ; j += i){
                        isPrime[j] = false;
                    }
                }
            }
            // for( int i = 0; i < isPrime.size(); i++ ){
            //     cout << isPrime[i] << endl;
            // }
        }
    public:
        vector<int> closestPrimes(int left, int right) {
    
            vector<bool>isPrime(right+1, true);
            vector<int>primes;
            SieveOfEratosthenes(right, isPrime);
    
            int minDiff = INT_MAX;
            vector<int>primePair = {-1, -1};
            
            for( int i = left; i < isPrime.size(); i++ ){
                if(isPrime[i] == true)
                primes.push_back(i);
            }
            
            if(primes.size() < 2) return primePair;
    
            for( int i = 0; i < primes.size()-1; i++ ){
                int diff = primes[i+1] - primes[i];
                // cout << primes[i] << " " << diff << " " << minDiff << endl;
                if(diff < minDiff){
                    minDiff = diff;
                    primePair = {primes[i], primes[i+1]};
                }
            }
            return primePair;
        }
    };