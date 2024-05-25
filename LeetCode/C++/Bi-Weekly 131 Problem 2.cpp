class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> all;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i] == x){
                all.push_back(i);
            }
        }
        vector<int> ans;
        for(int q:queries){
            if(q > all.size()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(all[q-1]);
            }
        }
        return ans;
    }
};