class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            
            int alternatingGroupsCount = 0;
            int l = 0;
            for( int i = 0; i < k-1; i++ ) colors.push_back(colors[i]);
            for( int r = 1; r < colors.size(); r++ ){
                if(colors[r-1] == colors[r]){
                    l = r;
                }
                if(r-l+1 >= k) alternatingGroupsCount++;
            }
            return alternatingGroupsCount;
        }
    };