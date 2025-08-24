class Solution {
public:
void sortByUnits(vector<vector<int>> &boxTypes) 
{
    sort(boxTypes.begin(), boxTypes.end(),
         [](const vector<int> &a, const vector<int> &b) 
         {
            return a[1] > b[1]; 
         });
}
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sortByUnits(boxTypes);
        int maxi = 0;
        for(int i=0;i<boxTypes.size();i++){
            int take = min(truckSize,boxTypes[i][0]);
            maxi += take*boxTypes[i][1];
            truckSize -= take;
        }
        return maxi;
    }
};