 
class Solution {
public:

    int characterReplacement(string s, int k) {
        int n = s.size();
 
       
        if (n == 0 || k < 0) {
            return 0;
        }
 
        vector<int> frequency(26, 0);
 
        int left = 0;
        int maxFrequency = 0;
        int maxLength = 0;
 
      
        for (int right = 0; right < n; right++) {
            int index = s[right] - 'A';
            frequency[index]++;
 
            maxFrequency = max(
                maxFrequency,
                frequency[index]
            );
 
            int currentLength =
                right - left + 1;
 
  
            if (currentLength - maxFrequency > k) {
                frequency[s[left] - 'A']--;
                left++;
            }
 
          
            currentLength = right - left + 1;
 
            maxLength = max(
                maxLength,
                currentLength
            );
        }
 
        return maxLength;
    }
};