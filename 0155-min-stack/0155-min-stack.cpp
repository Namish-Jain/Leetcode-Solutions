class MinStack {
private:
    vector<int> stack;
    vector<int> minimumStack;

public:
    MinStack() {}
    
    void push(int val) {
        stack.push_back(val);
        if (minimumStack.empty() || val <= minimumStack.back()) {
            minimumStack.push_back(val);
        }
    }
    
    void pop() {
        if (stack.empty()) return;
        if (stack.back() == minimumStack.back()) {
            minimumStack.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minimumStack.back();
    }
};