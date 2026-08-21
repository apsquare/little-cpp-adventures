/*
 * BEST TIME TO BUY AND SELL STOCK (brute force)
 *
 * Problem    : arr[i] is the price of a stock on day i. Buy on one day and
 *              sell on a later day. Print the maximum profit, or 0 if no
 *              profit is possible.
 * Input      : n, then n prices
 * Output     : the maximum profit
 * Idea       : Try every buy day i with every later sell day j.
 * Complexity : Time O(n^2)   Space O(1)
 */

#include<iostream>
#include<climits>


using namespace std;

int main(){


  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  
  int profit =0 ;
  int maxProfit = 0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      profit = arr[j] - arr[i];
      maxProfit = max(maxProfit,profit);
    }
    
  }

  cout << maxProfit << endl;

}