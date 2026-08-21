/*
 * MINIMUM DAYS TO MAKE M BOUQUETS
 *
 * Problem    : arr[i] is the day flower i blooms. Each bouquet needs k
 *              adjacent bloomed flowers. Print the earliest day on which m
 *              bouquets can be made, or -1 when there are not enough
 *              flowers.
 * Input      : n, then n bloom days, then m, then k
 * Output     : the minimum day, else -1
 * Idea       : Binary search the day between the earliest and the latest
 *              bloom; for a candidate day, sweep once counting runs of k
 *              adjacent bloomed flowers.
 * Complexity : Time O(n log(maxDay - minDay))   Space O(1)
 */

#include<iostream>
#include<numeric>
#include<algorithm>

using namespace std;




//! Helper function 
int bouqeuetsFormed(int arr[], int n , int m ,int k,int mid ){
  int current_bouquets = 0; // * Bouquets formed
  int current_flowers = 0; // * Adjacent flowers counted
  for(int i=0;i<n;i++){
    if(arr[i] <= mid ) {
    current_flowers++;
    if(current_flowers >= k){
      current_bouquets ++;
      current_flowers = 0;
    }
    }else {
      current_flowers = 0;
    }
  }

  return current_bouquets;
}


int main(){


  int n ,m ,k;
  cin >> n ;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cin >> m;
  cin >>k;

    // ! Not enough flowers
   if (1LL * m * k > n) {
        cout << -1 << endl;
        return 0;
    }



  // * Binary search range
  int right = *max_element(arr,arr+n); // * Maximum day
  int left = *min_element(arr,arr+n); // * Minimum day
  int answer = right;
  while(left <= right){
    int mid = left + (right-left)/2;

    if(bouqeuetsFormed(arr,n,m,k,mid) >= m){
      answer = mid;
      right = mid -1;
    }else{
      left = mid +1;
    }
  }

  cout << answer << endl;








}
