struct M{
  int h;
  int l;
  int v;
};
void update(vector<M> &v, M m, vector<int> &prices){
  for(auto &k : v){
    if(prices[m.h] > prices[k.h]){
      k.v = prices[m.h] - prices[k.l];
      k.h = m.h;
    }
  }
}
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if(prices.size() <= 1) return 0;
    if(prices.size() == 2) return prices[0] >= prices[1] ? 0 :  prices[1] - prices[0];
    int profit = 0;
    vector<M> ans;
    bool in = false;
    M m;
    m.v = 0;m.h = 0; m.l = 0;
    for(int i = 1; i < prices.size(); ++i){
      if(prices[i] > prices[i-1]){
        if(!in){
          in = true;
          m.l = i-1;
        }
        m.v = prices[i]-prices[m.l];
        m.h = i;
      }
      else{
        if(m.v){
          ans.push_back(m);
          update(ans, m, prices);
        }
        m.v = 0;
        in = false;
      }
    }
    if(in)
      ans.push_back(m);
    update(ans, m, prices);
    int v = 0;
    for(auto k : ans){
      if(k.v > v)
        v = k.v;
    }
    return v;
  }
};

