/*
 * SPLIT ARRAY LARGEST SUM
 *
 * Problem    : Split an array of non-negative integers into exactly k non-
 *              empty contiguous subarrays so that the largest subarray sum
 *              is as small as possible. Print that minimum possible largest
 *              sum.
 * Input      : n, then n integers, then k
 * Output     : the minimised largest subarray sum
 * Idea       : Binary search the answer between the largest element and the
 *              total sum; for a candidate limit, greedily count the
 *              subarrays it forces.
 * Complexity : Time O(n log(sum - max))   Space O(1)
 * TODO       : the search is inverted and the else branch is empty, so the
 *              loop never ends once the greedy count drops below k. It
 *              should be: count > k -> left = mid+1, otherwise answer = mid
 *              and right = mid-1.
 */

#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;




int helper(int arr[] ,int n , int k ,int mid ){
  int count = 1;
  int current_sum = 0;
  
  for(int i=0;i<n;i++){
    
    if(current_sum  +arr[i] <= mid){
      current_sum += arr[i];
    }else{
      count ++;
      current_sum = arr[i];
    }
  }
  return count;
}

int main(){

  int n , k;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cin >> k;

  int left = *max_element(arr,arr+n);
  int right = accumulate(arr,arr+n,0);
  int answer = right ; 
  //* We taken the maximum possible value as the initial answer because we are ultimately lookign for the smaller ones and of anyone exists then this will get replaced

  while(left <= right){
    int mid = left + (right-left)/2;
    if(helper(arr,n,k,mid) >= k){ 
      //* The maximum allowed sum (mid) is too small, causing more than k subarrays .Increase mid so more elements can fit into each subarray.
      answer = mid;
      left = mid + 1;
    }else{
      
    }
  }

  cout << answer <<endl;



}