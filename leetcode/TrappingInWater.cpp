class Solution {
public:
    int trap(vector<int>& height) {
        int capacity = 0;
        int R = -1;
        int L = 0;
        int VL = 0;
        int VR = 0;
        bool pattern = false;
        int dis = 0;
        for(int i = 0; i < height.size(); ++i) {
            if(height[i]) {
                if(pattern == false) {
                    L = i;
                    VL = height[i];
                }
                if(pattern == false) {
                    R = maxElement(height, i+1, VL);
                    if(R == height.size()) {
                        R = maxElement1(height, i+1, L);
                    }
                }
                else {
                    R = maxElement(height, i, VL);
                    if(R == height.size()) {
                        R = maxElement1(height, i, L);
                    }
                }
                if(R == height.size()) {
                    return capacity;
                }
                pattern = true;
                dis = R - L;
                if(dis != 1){
                    std::cout << L+1 << "\t" << R << "\t" << min(height[R], VL) << std::endl;
                    capacity = accmulate(L+1, R, min(height[R], VL), capacity, height);
                }
                 L = R;
                VL = height[R];
                i = R;
            }
        }
        return capacity;
    }
    int maxElement1(const std::vector<int> &in, int start, int lhs) {
        int max = 0;
        int i = 0;
        int index = 0;
        for(i = start; i < in.size(); ++i) {
            if(in[i] >= max && (i-lhs) != 1) {
                max = in[i];
                index = i;
            }
        }
        if(index == 0) {
            return i;
        }
        else {
            return index;
        }
    }
    int maxElement(const std::vector<int> &in, int start, int val) {
        int max = val;
        int i = 0;
        for(i = start; i < in.size(); ++i) {
            if(in[i] >= max) {
                max = in[i];
                return i;
            }
        }
        return i;
    }
    int accmulate(int lhs, int rhs, int bowie, int capacity, const std::vector<int> &height){
        for(;lhs < rhs; lhs++) {
             if((bowie - height[lhs]) < 0) {
                 continue;
             }
            capacity += bowie - height[lhs];
        }
        return capacity;
    }
 
};