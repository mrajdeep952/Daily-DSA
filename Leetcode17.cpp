class Solution {
    private:
        void getCombination(vector<string>& result, string& digits, string& str, unordered_map<char, string>& mpp, int index){
    
            if(index >= digits.length()){
                if(str.length() > 0)
                result.push_back(str);
                return;
            }
    
            for( int i = index; i < digits.length(); i++ ){
                string letter = mpp[digits[i]];
                for( int ch = 0; ch < letter.length(); ch++ ){
                    str += letter[ch];
                    getCombination(result, digits, str, mpp, index+1);
                    str.pop_back();
                }
            }
        }
    public:
        vector<string> letterCombinations(string digits) {
            
            vector<string>result;
            unordered_map<char, string> mpp = {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
            };
    
            string str = "";
            int index = 0;
            getCombination(result, digits, str, mpp, index);
            return result;
        }
    };