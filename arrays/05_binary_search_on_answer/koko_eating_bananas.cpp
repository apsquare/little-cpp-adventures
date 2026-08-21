/*
 * KOKO EATING BANANAS
 *
 * Problem    : n piles of bananas and h hours are given. In one hour Koko
 *              eats up to her chosen speed from a single pile. Print the
 *              smallest speed that lets her finish every pile within h
 *              hours.
 * Input      : n, then n pile sizes, then h
 * Output     : the minimum eating speed
 * Idea       : Binary search the speed between 1 and the largest pile; a
 *              speed works when the sum of ceil(pile / speed) is <= h.
 * Complexity : Time O(n log(maxPile))   Space O(1)
 */

#include<iostream>

using namespace std;


bool canFinish(int arr[],int n,int mid,int h){

  long long total_hours = 0;
  for(int i=0;i<n;i++){
    total_hours += (arr[i] + mid - 1) /mid;
  }

  return total_hours <= h;
}


int main(){
  int n ,h;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cin >> h;




  int maxPile = arr[n-1];
  for(int i=0;i<n;i++){
    maxPile = max(maxPile,arr[i]);
  }

  // Binary-search the eating speed
  int left = 1;
  int right= maxPile;
  int answer = maxPile;


  while (left <= right)
  {
    int mid = left + (right-left)/2;

    if(canFinish(arr,n,mid,h)){
      answer = mid;
      right = mid-1;
    }else{
      left = mid +1;
    }
  }
  


  cout << answer << endl;


  








}
