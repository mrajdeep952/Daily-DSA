class Solution {
    public:
        int bagOfTokensScore(vector<int>& tokens, int power) {
            
            int maxScore = 0;
            int start = 0;
            int end  = tokens.size()-1;
            sort(tokens.begin(), tokens.end());
            int currScore = 0;
            while(start <= end){
                while(start < tokens.size() && tokens[start] <= power){
                    // cout << "start " << start << endl;
                    power -= tokens[start];
                    currScore++;
                    maxScore = max(currScore, maxScore);
                    start++;
                }
                if(currScore > 0){
                    // cout << "end " << end << endl;
                    currScore--;
                    power += tokens[end];
                    end--;
                    maxScore = max(currScore, maxScore);
                }
                else return 0;
            }
            return maxScore;
        }
    };