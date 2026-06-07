class Solution {
public:
    bool checkValidString(string s) {
        //priority_queue<int> myHeap;
        int minopen = 0;
        int maxopen = 0;
        for ( char i : s ){
            if ( i == '('){
                minopen++;
                maxopen++;
            }
            else if ( i == ')'){
                minopen--;
                maxopen--;
            }
            else {
                minopen--;
                maxopen++;
            }

            if( maxopen < 0) return false;
            minopen = max(minopen,0);
        }

        return minopen == 0;
            

    }
};
