class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        map<int,int> ballColor;
        map<int,int> colCounter;
        vector<int> ans;
        for(vector<int> p:queries){
            if(ballColor.find(p[0]) != ballColor.end()){
                colCounter[ballColor[p[0]]]--;
                if(colCounter[ballColor[p[0]]] == 0){
                    auto it = colCounter.find(ballColor[p[0]]);
                    colCounter.erase(it);
                }
            }
            ballColor[p[0]] = p[1];
            colCounter[p[1]]++;
            ans.push_back(colCounter.size());
        }
        return ans;
    }
};