//my Solution
//
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int g_size = g.size();
        int s_size = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int g_index = 0;
        int s_index = 0;

        while (g_index < g_size && s_index < s_size ){
            if(s[s_index] >= g[g_index]){
                s_index++;
            }
            g_index++;
        }
        return s_index;
    }
};


//--------------------------------------------------------------------------------------


class Solution {
public:
// for optimuze the leetcode runtime 
    inline static const auto io_opt = []() { 
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        return 0; 
    }();

    int findContentChildren(vector<int>& g, vector<int>& s) {
        int g_size = g.size();
        int s_size = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int g_index = 0;
        int s_index = 0;

        while (g_index < g_size && s_index < s_size ){
            if(s[s_index] >= g[g_index]){
                g_index++;
            }
            s_index++;
        }
        return g_index;
    }
};
