class MinStack {
    stack<pair<int,int>> s;
    int minVal;
public:
    MinStack() {

    }
    
    void push(int val) {
        if(s.empty()){
            minVal = val;
            s.push(make_pair(val, minVal));
        }
        else{
            if(val <= minVal){
                minVal = val;
            }
        s.push({val, minVal});
        }
    }
    
    void pop() {
        if(!s.empty()){
            s.pop();
            if(!s.empty()){
                minVal = s.top().second;
            }
        }
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */