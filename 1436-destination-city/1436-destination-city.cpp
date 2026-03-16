class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sourceCities;
        unordered_set<string> destinationCities;
        for (const auto& path : paths) {
            sourceCities.insert(path[0]);
            destinationCities.insert(path[1]);
        }
        for (const auto& city : destinationCities) {
            if (sourceCities.find(city) == sourceCities.end()) {
                return city;
            }
        }
        return "";
    }
};