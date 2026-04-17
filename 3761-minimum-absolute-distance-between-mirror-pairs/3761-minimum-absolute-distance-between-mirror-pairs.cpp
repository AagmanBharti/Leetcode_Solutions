class Solution {
public:
    int reverseNumber(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp; // reversed value -> latest index
        int dist = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {
            // check if current number matches reverse of some previous
            if (mp.count(nums[j])) {
                dist = min(dist, j - mp[nums[j]]);
            }

            // store reverse of current number
            int rev = reverseNumber(nums[j]);
            mp[rev] = j;  //store latest index
        }

        return dist == INT_MAX ? -1 : dist;
    }
};