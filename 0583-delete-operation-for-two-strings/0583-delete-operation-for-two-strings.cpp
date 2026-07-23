class Solution {
public:
    int minDistance(string word1, string word2) {      
	vector<vector<int> >dp(size(word1) + 1, vector<int>(size(word2) + 1));
	for(int i = 0; i <= size(word1); i++) 
		for(int j = 0; j <= size(word2); j++) 
			if(!i || !j) dp[i][j] = i + j;
			else dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : 1 + min(dp[i - 1][j], dp[i][j - 1]);
	return dp[size(word1)][size(word2)];
    }
};