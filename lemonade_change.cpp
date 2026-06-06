class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       //vector<int> change;
        int change = 0;
        int n = bills.size();
        int coin_5 = 0;
        int coin_10 = 0;
       
        for(int i = 0; i < n; i++){
            if ( bills[i] == 5){
                //change.push_back(bills[i]);
                coin_5++;
            }
            if ( bills[i] == 10){
                //int temp = bills[i] - 5;
                coin_10++;
            }
            change = bills[i] - 5;
            if( change == 5){
                if( change > 0 ){
                    coin_5--;
                }
                else return false;
            }
            
            if( change == 15){
                if( coin_10 > 0 || coin_5 > 0){
                    coin_10--;
                    coin_5--;
                }
                else return false;
            }
        
            
        }
        return true;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       //vector<int> change;
        int change = 0;
        int n = bills.size();
        int coin_5 = 0;
        int coin_10 = 0;
       
        for(int i = 0; i < n; i++){
            if ( bills[i] == 5){
                //change.push_back(bills[i]);
                coin_5++;
            }
            if ( bills[i] == 10){
                //int temp = bills[i] - 5;
                if( coin_5 > 0){
                    coin_10++;
                    coin_5--;
                }
                else return false;
                
            }
            change = bills[i] - 5;
            // extra line fix later
            

            if( change == 15){
                if( coin_10 > 0 && coin_5 > 0){
                    coin_10--;
                    coin_5--;
                }
                else if(coin_5 >= 3){
                    coin_5 -=3;
                }
                else return false;
            }
        
            
        }
        return true;
    }
};

