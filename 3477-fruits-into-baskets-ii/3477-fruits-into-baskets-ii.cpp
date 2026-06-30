class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        int n = fruits.size();
        vector<bool> used(n,false);

        for(int i = 0;i<fruits.size();i++){
            bool placed = false;

            for(int j = 0;j<n;j++){
                if(!used[j] && baskets[j] >= fruits[i]){
                    used[j] = true;
                    placed = true;
                    break;
                }
            }

            if(!placed) unplaced++;
        }
        return unplaced;
    }
};