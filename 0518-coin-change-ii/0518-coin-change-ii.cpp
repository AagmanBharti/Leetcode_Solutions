class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<unsigned int>prev(amount+1,0);
        vector<unsigned int>curr(amount+1,0);

        for(int idx=0;idx<n;idx++){
            for(int amt=0;amt<amount+1;amt++){
                if(amt==0){
                    curr[amt]=1;
                    continue;
                }
                if(idx==0){
                    curr[amt]=amt%coins[idx]==0;
                    continue;
                }

                unsigned int notTake=0;
                if(idx>0)notTake=prev[amt];
                unsigned int take=0;
                if(coins[idx]<=amt)take=curr[amt-coins[idx]];
                curr[amt]=notTake+take;
            }
            prev=curr;
        }
        return (int)prev[amount];
    }
};
