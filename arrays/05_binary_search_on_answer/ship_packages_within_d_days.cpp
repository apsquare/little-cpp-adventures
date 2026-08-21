/*
 * CAPACITY TO SHIP PACKAGES WITHIN D DAYS
 *
 * Problem    : Packages must be shipped in their given order within D days.
 *              Print the smallest ship capacity that makes this possible.
 * Input      : n, then n package weights, then D
 * Output     : the minimum capacity
 * Idea       : Binary search the capacity between the heaviest package and
 *              the total weight; for a candidate, greedily fill days and
 *              count them.
 * Complexity : Time O(n log(sum - max))   Space O(1)
 */

#include<iostream>
#include<numeric>
#include<algorithm>


using namespace std;


bool canLoad(int arr[] ,int n  , int capacity , int D ){
  int days = 1;
  int currentLoad = 0;
  for(int i=0;i<n;i++){
    if(currentLoad + arr[i] <= capacity){
      currentLoad += arr[i];
    }else{
      days++;
      currentLoad = arr[i];
    }
  }
  return days <= D;
}

int main(){

  int n , D;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cin >> D;

  
  // The weights are ordered
  int left = *max_element(arr, arr + n);
  int right = accumulate(arr,arr+n,0);
  int requiredCapacity =  right;

  while (left <= right)
  {
    int mid = left + (right - left)/ 2;

    if(canLoad(arr,n,mid,D)){
      requiredCapacity = mid;
      right = mid -1 ;
    }else{
      left = mid +1;
    }
  }
  

  cout << requiredCapacity << endl;

  



}
