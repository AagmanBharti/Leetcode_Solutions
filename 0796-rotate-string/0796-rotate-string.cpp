class Solution {
public:

    string rotate(string s, int k) {
        int n = s.size();
        k %= n;

        reverse(s.begin(), s.begin() + k);
        reverse(s.begin() + k, s.end());
        reverse(s.begin(), s.end());

        return s;
    }

    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            if (rotate(s, i) == goal)
                return true;
        }

        return false;
    }
};