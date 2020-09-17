class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        
        int mins = customers.size();
        
//         // Just extra useless optimization
//         if(X >= mins){
//             int k = 0;
//             while(mins--) 
//                 k+= customers[mins];
//             return k;
//         }
//         // End
        
        
        int ans = 0;
        for(int i = 0; i < mins; i++){
            if(grumpy[i] != 1){
                ans += customers[i];
                customers[i] = 0;
            }
        }

        int window_max = 0;        
        for(int i = 0; i < X; i++){
            window_max += customers[i];
        }
        
        int window_sum = window_max;
        for(int i = X; i < mins; i++){
            window_sum += (customers[i] - customers[i-X]);
            if(window_sum > window_max){
                window_max = window_sum;
            }
        }
        
        ans += window_max;

        return ans;
    }
};
