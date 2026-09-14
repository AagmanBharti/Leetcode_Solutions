class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mpp1, mpp2;

        // Store index of restaurants in list1
        for(int i = 0; i < list1.size(); i++) {
            mpp1[list1[i]] = i;
        }

        // Store index of restaurants in list2
        for(int i = 0; i < list2.size(); i++) {
            mpp2[list2[i]] = i;
        }

        int min_sum = INT_MAX;
        vector<string> ans;

        for(int i = 0; i < list1.size(); i++) {

            // Check if restaurant exists in list2
            if(mpp2.find(list1[i]) != mpp2.end()) {

                int sum = mpp1[list1[i]] + mpp2[list1[i]];

                if(sum < min_sum) {
                    min_sum = sum;
                    ans.clear();
                    ans.push_back(list1[i]);
                }
                else if(sum == min_sum) {
                    ans.push_back(list1[i]);
                }
            }
        }

        return ans;
    }
};