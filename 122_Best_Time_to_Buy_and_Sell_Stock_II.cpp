#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        // we will traverse from second element , and we buy at bottom and sell at peak
        for(int i =1 ; i <n  ; i++){
            if(prices[i]>prices[i-1]){ // only focusing on profit(peaks)
                profit += prices[i]-prices[i-1]; // adding profits , and ignoring when there is no profit , so eventually we will get the entire profit , when array ends 
            }
        }
        return profit;
    }

int main(){
    vector<int>prices = { 7,1,5,3,6,4 };
    cout<<" max profit  is : " << maxProfit(prices) <<endl; 
}
