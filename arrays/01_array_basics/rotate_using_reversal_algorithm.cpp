/*
 * ROTATE AN ARRAY LEFT BY K (reversal algorithm)
 *
 * Problem    : Given an array of n integers and a number k, rotate the array
 *              to the left by k positions, in place.
 * Input      : n, then n integers, then k
 * Output     : the rotated array
 * Idea       : Reverse the first k elements, reverse the remaining n-k, then
 *              reverse the whole array.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>

using namespace std;

void reverseArray(int arr[], int left , int right,int n){
  
  while (left < right)
  {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    left++ ;
    right-- ;
  }
  

}


int main(){

  int n , k;
  cin >> n ;

  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  cin >> k;
  k= k %n ;

 reverseArray(arr,0,k-1,n);
 reverseArray(arr,k,n-1,n);
 reverseArray(arr,0,n-1,n);

 for(int i=0;i<n;i++){
  cout << arr[i] << " ";
 }




  


}