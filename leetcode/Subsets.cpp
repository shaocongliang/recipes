class Solution {
public:
void permute(vector<vector<int> > &ans, vector<int> v, vector<int> cands, int cur, int layer)
{
    if (cur == layer)
    {
        ans.push_back(v);
        return;
    }
    for (int i = 0; i < cands.size(); ++i)
    {
        v.push_back(cands[i]);
        vector<int> t;
        for(int k = i+1; k < cands.size(); ++k) {
            t.push_back(cands[k]);
        }
        permute(ans, v, t, cur + 1, layer);
        v.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> v;
    for (int i = 0; i <= nums.size(); ++i)
    {
        permute(ans, v, nums, 0, i);
    }
    return ans;
}
};