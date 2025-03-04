// Backtracking solution
class Solution {
    private:
        bool powerOfThree(long long& sum, long long power, int n){
            
            if(sum >  n) return false;
            if (power > LLONG_MAX / 3) return false;
            if(sum ==  n) return true;
            
            // pick current Power and move forward
            sum += power;
            if(powerOfThree(sum, power*3, n)) return true;
            sum -= power;
            // skip the current power and move forward 
            if(powerOfThree(sum, power*3, n)) return true;
    
            return false;
        }
    public:
        bool checkPowersOfThree(int n) {
            
            long long sum = 0;
            return powerOfThree(sum, 1, n);
        }
    };