using ll = long long;
vector<ll> od, ev;
bool initDone = false;

class Solution {
public:
    void init() {
        if (initDone) return;
        
        for (int len = 1; len <= 10; ++len) {
            int k = (len - 1) / 2;
            ll start = 1;
            for (int i = 0; i < k; i++) start *= 10;
            ll end = start * 10;

            for (ll i = start; i < end; ++i) {
                ll p = i;
                ll temp = i;
                
                if (len % 2 != 0) temp /= 10;
                
                while (temp > 0) {
                    p = p * 10 + (temp % 10);
                    temp /= 10;
                }
                
                if (p % 2 == 0) ev.push_back(p);
                else od.push_back(p);
            }
        }
        initDone = true;
    }

    ll getMeGreater(vector<ll>& temp, int x){
        ll o = 1e18;
        auto it = lower_bound(temp.begin(), temp.end(), x);

            if(it != temp.end()){
                o = min(o, 1LL*(abs(x - *it)));
            }

            if(it != temp.begin()){
                auto p = prev(it);
                o = min(o, 1LL*(abs(x - *p)));
            }

        return o;
    }

    ll getMeSmaller(vector<ll>& temp, int x){
        int i = 0, j = temp.size() - 1;

        ll it = -1;
        while(i <= j){
            int mid = (i + j)/2;
            if(temp[mid] <= x){
                it = mid;
                i = mid + 1;
            }else j = mid - 1;
        }
        if(it == -1) return 1e18;
        return x - temp[it];
    }

    
    ll minOperations(vector<int>& a) {
        init();
        
        ll ans = 0;
        for(auto x: a){
            ll o = 1e18;
            if(x&1){
                o = getMeGreater(od, x);
                o = min(o, getMeSmaller(od, x));
            }
            else{
                o = getMeGreater(ev, x);
                o = min(o, getMeSmaller(ev, x));
            }
            
            if(o != 1e18) ans += o;
        }
        return ans/2;
        
    }
};