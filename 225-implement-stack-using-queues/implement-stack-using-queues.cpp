class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        while(q1.size()>0){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(q2.size()>0){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
       int x=q1.front();
        q1.pop();
       return x;   
    }
    
    int top() {
       return q1.front();
    }
    
    bool empty() {
       return q1.size()==0; 
    }
};