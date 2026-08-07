class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word,
             string beginWord,
             vector<string>& path) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &par : parent[word]) {
            path.push_back(par);
            dfs(par, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        unordered_set<string> currLevel;
        currLevel.insert(beginWord);

        bool found = false;

        while (!currLevel.empty() && !found) {

            for (auto &w : currLevel)
                dict.erase(w);

            unordered_set<string> nextLevel;

            for (auto word : currLevel) {

                string originalWord = word;

                for (int i = 0; i < word.size(); i++) {

                    char orig = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        word[i] = ch;

                        if (!dict.count(word))
                            continue;

                        nextLevel.insert(word);
                        parent[word].push_back(originalWord);

                        if (word == endWord)
                            found = true;
                    }

                    word[i] = orig;
                }
            }

            currLevel = nextLevel;
        }

        if (!found)
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};