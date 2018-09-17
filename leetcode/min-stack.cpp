class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(is.size() == 0){
            minval_ = x;
        }
        is.push_back(x);
        if(x < minval_)
            minval_ = x;
    }
    
    void pop() {
      is.erase(is.end()-1);
      updateMinVal();
    }
    
    int top() {
        return is.back();
    }
    
    int getMin() {
        return minval_;
    }
private:
    void updateMinVal(){
        if(is.size() != 0) {
            minval_ = is[0];
        }
        for(int i = 1; i < is.size(); ++i) {
            if(is[i] < minval_)
                minval_ = is[i];
        }
    }
    vector<int> is;
    int minval_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
