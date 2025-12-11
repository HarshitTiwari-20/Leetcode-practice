#include <bits/stdc++.h>

int sub(vector<int> a , int k){
  int ar = 0;
  map<int,int> mpp;
  mpp[ar]++;
  int cnt = 0;
  for(int i = 0; i < a.size(); i++){
    ar = ar ^ a[i];
    int x = ar ^ k;
    cnt += mpp[x];
    mpp[ar]++;
  }
  return cnt;
}
