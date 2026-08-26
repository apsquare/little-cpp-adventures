#include<iostream>
#include <cfloat>

//! maximum_average_subarray
//! Question: Given an integer array arr and an integer k, find a contiguous subarray of exactly k elements that has the maximum average, and return that maximum average. Solve using Sliding Window in O(n) time.
//! Example: nums = [1,12,-5,-6,50,3], k = 4 → output 12.75, because the subarray [12,-5,-6,50] has sum 51, so its average is 51 / 4 = 12.75.


using namespace std;

int main(){

  int n , k;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cin >> k;


  int sum = 0;
  float maxAvg = -FLT_MAX;
  int left =0 ;
  int right = 0;

  while(right < n){
    sum += arr[right];
    if(right - left + 1 == k){
      maxAvg = max(maxAvg, float(sum)/k);
      sum -= arr[left];
      left++;
    }
    right++;
  }

  cout << maxAvg << endl;







}