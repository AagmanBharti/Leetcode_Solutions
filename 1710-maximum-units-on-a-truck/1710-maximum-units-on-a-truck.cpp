class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes,
                                       int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });

        int total_units = 0;

        for (auto& it : boxTypes) {
            int number = it[0];
            int unitNo = it[1];

            int take = min(truckSize, number);
            total_units += take * unitNo;
            truckSize -= take;
        }
        
        return total_units;
    }
};