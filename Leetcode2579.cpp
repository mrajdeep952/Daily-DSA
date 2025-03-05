class Solution {
    public:
        long long coloredCells(int n) {
            
            long long coloredCells = 1;
            long long commonDiff = 4;
            for( int i = 2; i <= n; i++ ){
                coloredCells += commonDiff;
                commonDiff += 4;
            }
            return coloredCells;
        }
    };