 class MinStack {
public:
    stack<int> st;
    stack<int> minst;

    MinStack() {
    }

    void push(int value) {
        st.push(value);

        if (minst.empty() || value <= minst.top()) {
            minst.push(value);
        }
    }

    void pop() {
        if (st.top() == minst.top()) {
            minst.pop();
        }

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minst.top();
    }
};