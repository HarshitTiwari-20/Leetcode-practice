class Solution {
  public :
    int lengthOfLongestSustring(string s){
      vector<int> mpp(256, -1);
      int left = 0;
      int rigth = 0;
      int n = s.size();
      int len = 0;
      while(rigth < n){
        if(mpp[s[rigth]] != -1) left = max(mpp[s[rigth]] + 1, left);
        mpp[s[rigth]] = rigth;
        len = max(len, rigth - left + 1);
        rigth++;
      }
      return len;
    }
};
