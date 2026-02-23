class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int result = 0;

        for(int i = 0;i < operations.size();i++){
            if(operations[i] == "+"){
                int prev = st.top();
                st.pop();
                int score = prev + st.top();
                st.push(prev);
                st.push(score);
                result += score;
            }
            else if(operations[i] == "C"){
                result -= st.top();
                st.pop();
            }
            else if(operations[i] == "D"){
                int peek = st.top();
                result += peek*2;
                st.push(peek*2);
            }
            else {
                result += (stoi(operations[i]));
                st.push(stoi(operations[i]));
            }
        }
    return result;
    }
};