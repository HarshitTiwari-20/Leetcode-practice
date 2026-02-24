class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> main;
        vector<int> result;

        for(int i : a) {
            main[i]++;
        }
        
        for(int x : b) {
            main[x]++;
        }
        
        for(auto const& [val, count] : main) {
            result.push_back(val);
        }
        
        return result;
    }
};
