class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();
        set<int> ss;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i != j){
                    if(nums[i] == nums[j]){
                        ss.insert(nums[i]);
                    }
                }
            }
        }
        int ans = 0;
        for(int x:ss){
            ans ^= x;
        }
        return ans;
    }
};