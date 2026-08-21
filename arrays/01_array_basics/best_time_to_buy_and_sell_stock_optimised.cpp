/*
 * BEST TIME TO BUY AND SELL STOCK (single pass)
 *
 * Problem    : arr[i] is the price of a stock on day i. Buy on one day and
 *              sell on a later day. Print the maximum profit, or 0 if no
 *              profit is possible.
 * Input      : n, then n prices
 * Output     : the maximum profit
 * Idea       : Track the cheapest price seen so far and the best profit
 *              against it.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>


using namespace std;

int main(){

  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int minSoFar = arr[0];
  int maxProfit = 0;
  for(int i=0;i<n;i++){
    int profit = arr[i] - minSoFar;
    maxProfit = max(profit,maxProfit);
    minSoFar = min(minSoFar,arr[i]);
  }

  cout << maxProfit << endl;


}