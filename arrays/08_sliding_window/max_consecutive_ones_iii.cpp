#include<iostream>

using namespace std;


//! Question: Given a binary array nums containing only 0s and 1s and an integer k, you may change at most k zeros into ones. Find the maximum number of consecutive 1s you can obtain after performing at most k such changes.
//! Example: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2 → output 6, because we can flip two zeros to obtain a contiguous sequence of 6 ones.


int main(){

  int n , k;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cin >> k;

  int left =0 ;
  int right =0 ;
  int zeroes = 0; //?This is the count of zeroes we currently have 
  int ones = 0; //?This is the count of ones we currently have 
  int max_length = INT_MIN;
  

  while(right < n){


    if(arr[right] == 0){
      zeroes++;
    }


    while(zeroes > k ){ //? Currently we have more zeroes that what we can flip so we will shrink the window till we have k number of zeroes 
      if(arr[left] ==0 ){
        zeroes--;
      }
      left++;
    }



      max_length = max(max_length,right-left+1); //? Now we have only as many zeroes that we can flip 
      right++;
    
  }

  cout << max_length << endl;






}