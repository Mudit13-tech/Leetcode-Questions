class MyStack {
private: 
    queue<int> s;
public:
    MyStack() {}   
    void push(int x) {
        if(s.size() == 0){
            s.push(x);
            return;
        }
        s.push(x);
        int n = s.size();
        for(int i = 0;i<n-1;i++){
            int temp = s.front();
            s.pop();
            s.push(temp);
        }  
    }
    int pop() {
        int del = s.front();
        s.pop();
        return del;      
    }
    
    int top() {
        int first = s.front();
        return first;       
    } 

    bool empty() {
        if(s.size()>0){
            return false;
        }
        return true;      
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */