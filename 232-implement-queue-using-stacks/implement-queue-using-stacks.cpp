class MyQueue {
private:
    stack<int> mainStack;

public:
    void push(int x) {
        stack<int> temp;

        while (!mainStack.empty()) {
            temp.push(mainStack.top());
            mainStack.pop();
        }

        mainStack.push(x);

        while (!temp.empty()) {
            mainStack.push(temp.top());
            temp.pop();
        }
    }

    int pop() {
        int front = mainStack.top();
        mainStack.pop();
        return front;
    }

    int peek() {
        return mainStack.top();
    }

    bool empty() {
        return mainStack.empty();
    }
};