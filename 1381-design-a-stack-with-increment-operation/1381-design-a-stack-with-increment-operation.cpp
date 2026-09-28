class CustomStack {
public:
    stack<int> st;
    stack<int> helper;
    int n;

    CustomStack(int maxSize) { n = maxSize; }

    void push(int x) {
        if (st.size() < n) {
            st.push(x);
        }
    }

    int pop() {
        if (st.empty()) {
            return -1;
        }

        int val = st.top();
        st.pop();
        return val;
    }

    void increment(int k, int val) {
        int count = min((int)st.size(), k);

        while (st.size() > count) {
            helper.push(st.top());
            st.pop();
        }

        stack<int> temp;

        while (!st.empty()) {
            temp.push(st.top() + val);
            st.pop();
        }

        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

        while (!helper.empty()) {
            st.push(helper.top());
            helper.pop();
        }
    }
};