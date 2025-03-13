class Solution {
    private:
        void createCombination(vector<vector<int>>& requiredCombination, vector<int>& candidates, int target, int index, vector<int>& currentSet){
    
            if(index >= candidates.size())
            return;
    
            if(target == 0){
                requiredCombination.push_back(currentSet);
                return;
            }
    
            // take the current index element and go forward 
            if(candidates[index] <= target){
                currentSet.push_back(candidates[index]);
                createCombination(requiredCombination, candidates, target - candidates[index], index, currentSet);
                currentSet.pop_back();
            }
            // current element is greater so leave current element and go forward
            createCombination(requiredCombination, candidates, target, index+1, currentSet);
    
        }
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            
            vector<vector<int>>requiredCombination;
            vector<int>set;
            int index = 0;
            int sum = 0;
            createCombination(requiredCombination, candidates, target, index, set);
            return requiredCombination;
        }
    };