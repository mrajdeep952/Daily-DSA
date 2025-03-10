class Solution {
    private:
        long long getCount(string& word, int k){
            
            unordered_map<char, int>isVowel;
            long consonantCount = 0;
            long long subStringsCount = 0;
            long long l = 0; 
            long long r = 0;
    
            while(r < word.length()){
                if(word[r] == 'a' || word[r] == 'e' || word[r] == 'i' || word[r] == 'o' || word[r] == 'u'){
                    isVowel[word[r]]++;
                }
                else{
                    consonantCount++;
                }
                while(isVowel.size() == 5 && consonantCount >= k){
                    subStringsCount += word.length() - r;
                    if(word[l] == 'a' || word[l] == 'e' || word[l] == 'i' || word[l] == 'o' || word[l] == 'u'){
                        isVowel[word[l]]--;
                        if(isVowel[word[l]] == 0) isVowel.erase(word[l]);
                    }
                    else{
                        consonantCount--;
                    }
                    l++;
                }
                r++;
            }
            // cout << subStringsCount << endl;
            return subStringsCount;
        }
    public:
        long long countOfSubstrings(string word, int k) {
            
            return getCount(word, k) - getCount(word, k+1);
        }
    };