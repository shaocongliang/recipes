class Solution
{
  public:
    void combination(std::vector<std::vector<int>> &res, std::vector<int> cur, const std::vector<int> &in, int sum, int pos, int target)
    {
        for (int i = pos; i < in.size(); ++i)
        {
            sum += in[i];
            if (sum <= target)
            {
                cur.push_back(in[i]);
                if (sum == target)
                {
                    res.push_back(cur);
                    cur.pop_back();
                    sum -= in[i];
                    continue;
                }
            }
            else
            {
                sum -= in[i];
                continue;
            }
            combination(res, cur, in, sum, i, target);
            sum -= in[i];
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        std::vector<int> cur;
        std::vector<std::vector<int>> res;
        combination(res, cur, candidates, 0, 0, target);
        return res;
    }
};