class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()) return s;

        int idx = 0, dir = 1;
        vector<vector<char>> rows(numRows);

        for(char c : s){
            rows[idx].push_back(c);
            if(idx == 0) dir = 1;
            else if(idx == numRows - 1){
                dir = -1;
            }
            idx += dir;
        }

        string result;
        for(const auto& row : rows){
            for(char c : row){
                result += c;
            }
        }
        return result;
    }
};