/*
 * SMALLEST DIVISOR GIVEN A THRESHOLD
 *
 * Problem    : Divide every element by a chosen positive divisor, round each
 *              result up, and add them. Print the smallest divisor whose
 *              total is <= threshold.
 * Input      : n, then n integers, then threshold
 * Output     : the smallest valid divisor
 * Idea       : Binary search the divisor between 1 and the largest element;
 *              the total sum falls as the divisor grows.
 * Complexity : Time O(n log(max))   Space O(1)
 */

#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;





int helper(int arr[], int  n  ,int mid){
  int current_sum = 0;
  for(int i=0;i<n;i++){
    current_sum += ceil(arr[i] + mid -1)/mid; //*applying ceil division
  }
  return current_sum;

} 


int main(){

  int n , threshold ;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cin >> threshold;

  int left = 1 ;//*smallest positive divisor any number can have 
  int right =  *max_element(arr,arr+n);
  int answer = right ;

  while (left <= right)
  {
    int mid =  left + (right - left)/2;
    if(helper(arr,n,mid) <= threshold ){
      answer = mid ;
      right = mid -1;
    }else{
      left = mid + 1;
    }

  }

  cout <<  answer << endl;
  




}