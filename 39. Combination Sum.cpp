class Solution {
private: 
    void combinationSum(vector<int>& candidates, int target, vector<vector<int>> &output, vector<int> &temp, int index){
        if(index == candidates.size()){
            if(target == 0){
                output.push_back(temp);
            }
            return;
        }
        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            combinationSum(candidates, target-candidates[index], output, temp, index);
            temp.pop_back();
        }
        combinationSum(candidates, target, output, temp, index+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> temp;
        combinationSum(candidates, target, output, temp, 0);
        return output;
    }
};
