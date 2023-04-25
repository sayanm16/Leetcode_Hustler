class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] <= 0 or nums[i] > n) {
                nums[i] = n+1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(abs(nums[i]) > n) continue;
            int id = abs(nums[i]);
            nums[id-1] = -1 * abs(nums[id-1]);
        }
        int ans = n + 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans = i+1;
                break;
            }
        }
        return ans;
    }  
};
