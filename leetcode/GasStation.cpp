class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int oil = 0;
        int len = gas.size();
        int next = 0;
        int end = gas.size() - 1;
        int remained = 0;
        for(int i = 0; i < len; ++i) {
            oil = gas[i];
            int start = i;
            while(true) {
                if(start == end) next = 0;
                else next = start+1;
                remained = oil - cost[start];
                if(next == i && remained >=0) {
                    return i;
                }
                if(remained < 0)
                    break;
                else oil = remained + gas[next];
                start = next;
            }
        }
        return -1;
    }
};