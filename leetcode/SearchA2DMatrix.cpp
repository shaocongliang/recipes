class Solution {
public:
    int binarySearch(const vector<int> &v, int target){
        int high = v.size() - 1;
        int low = 0;
        int mid = 0;
        while(low <= high) {
            mid = (low+high)/2;
            if(v[mid] > target){
                high = mid -1;
            }
            else if(v[mid] < target){
                low = mid+1;
            }
            else {
                break;
            }
        }
        return low <= high? mid : -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> v;
        for(auto ii : matrix)
            for(auto jj : ii)
                v.push_back(jj);
        return binarySearch(v, target) == -1? false : true;
    }
};
