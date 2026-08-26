#include<iostream>
#include <algorithm>
#include <climits>

using namespace std;


//! Question: Given an array of positive integers nums and a positive integer target, find the minimum length of a contiguous subarray whose sum is greater than or equal to target. If no such subarray exists, return 0.

int main(){


  int n , target;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cin >> target;


  int min_length = INT_MAX;
  int left =0 ;
  int right =0 ;
  int sum = 0;


  while(right < n){

    sum+= arr[right];

    while(sum >= target){
      min_length = min(min_length,right-left+1);
      sum -= arr[left];
      left++;
    }

    right++;

  }

 if(min_length == INT_MAX){
    cout << 0 << endl;
  }else{
      cout << min_length << endl;
  }



}