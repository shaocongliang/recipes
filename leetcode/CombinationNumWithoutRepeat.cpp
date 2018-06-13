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
                    insert(res, cur);
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
            combination(res, cur, in, sum, i + 1, target);
            sum -= in[i];
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> cur;
        std::vector<std::vector<int>> res;
        combination(res, cur, candidates, 0, 0, target);
        return res;
    }
    void insert(std::vector<std::vector<int>> &ivec, std::vector<int> &in)
    {
        for (auto it : ivec)
        {
            if (std::equal(it.begin(), it.end(), in.begin()))
            {
                return;
            }
        }
        ivec.push_back(in);
    }
};