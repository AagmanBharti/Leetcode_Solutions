class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> indices;

        for(int i = 0; i < s.size();i++){
            if(s[i] == c){
                indices.push_back(i);
            }
        }

        vector<int> answer(s.size());
        
        for(int i = 0;i < s.size();i++){
            if(s[i] == c){
                answer[i] = 0;
            }
            else {
                int dist = INT_MAX;
                for(int j = 0;j < indices.size();j++){
                    dist = min(dist, abs(i-indices[j]));
                }
                answer[i] = dist;
            }
        }
        return answer;
    }
};