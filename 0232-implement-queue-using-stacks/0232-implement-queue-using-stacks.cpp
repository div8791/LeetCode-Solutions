class MyQueue {
public:
  stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s2.empty()){
          s1.push(s2.top());
          s2.pop();
        }
      s2.push(x);
      while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
      }
    }
    
    int pop() {
        int x = s2.top();
      s2.pop();
      return x;
    }
    
    int peek() {
        return s2.top();
    }
    
    bool empty() {
        if(s2.empty()){
          return true;
        }
      return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */