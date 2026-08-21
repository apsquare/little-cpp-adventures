/*
 * AGGRESSIVE COWS
 *
 * Problem    : Given n stall positions and k cows, place the cows so that
 *              the minimum distance between any two of them is as large as
 *              possible. Print that largest minimum distance.
 * Input      : n, then n stall positions, then k
 * Output     : the largest possible minimum distance
 * Idea       : Sort the stalls and binary search the answer: for a candidate
 *              distance, greedily place cows and check whether all k fit.
 * Complexity : Time O(n log n + n log(maxPos - minPos))   Space O(1)
 */

#include<iostream>
#include <algorithm>

using namespace std;

bool canPlace(int arr[], int n, int k ,int distance ){
  int cowCount = 1;
  int lastPosition = arr[0];

  for(int i=1;i<n;i++){
    if(arr[i] - lastPosition >= distance){
      cowCount++;
      lastPosition = arr[i];
    }

    if(cowCount >= k){
      return true;
    }


  }

  return false ;




}


int main(){
  int n, k;
  cin >> n ;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  sort(arr,arr+n);

  cin >> k;


  int left = 1;
  int right = arr[n-1] - arr[0];
  int answer = 0;

  while(left <= right){

    int mid = left + (right-left)/2;

    if(canPlace(arr,n,k,mid)){
      answer = mid;
      left = mid + 1;
    }else{
      right = mid -1 ;
    }

  }

  cout << answer << endl;




}

