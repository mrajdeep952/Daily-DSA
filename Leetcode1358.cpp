class Solution {
    public:
        int numberOfSubstrings(string s) {
            
            int l = 0;
            int r = 0;
            int len = s.length();
            unordered_map<char, int>mpp;
            int charCount = 0;
            int substringCount = 0;
            while(r < len){
                if(s[r] == 'a' || s[r] == 'b' || s[r] == 'c'){
                    mpp[s[r]]++;
                    charCount++;
                }
                while(mpp.size() == 3 && charCount >= 3){
                    substringCount += len - r;
                    mpp[s[l]]--;
                    charCount--;
                    if(mpp[s[l]] == 0) mpp.erase(s[l]);
                    l++;
                }
                r++;
            }
            return substringCount;
        }
    };
    
    //Bruteforce Solution 
    class Solution1 {
    public:
        int numberOfSubstrings(string s) {
    
            int counter = 0;
            for( int i = 0; i < s.length(); i++ ){
                vector<int>visited(3, 0);
                for( int j = i; j < s.length(); j++ ){
                    visited[s[j] - 'a'] = 1;
                    if(visited[0] + visited[1] + visited[2] == 3){
                        counter += s.length() - j;
                        break;
                    }
                }
            }
            return counter;
        }
    };
    
    // Optimal Solution
    class Solution2 {
    public:
        int numberOfSubstrings(string s) {
    
            int counter = 0;
            int r = 0;
            vector<int>lastseen(3,-1);
            while(r < s.length()){
                lastseen[s[r] - 'a'] = r;
                if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
                    counter += min(min(lastseen[0], lastseen[1]), lastseen[2]) + 1;
                }
                r++;
            }
            return counter;
        }
    };