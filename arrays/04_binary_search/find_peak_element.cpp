/*
 * FIND A PEAK ELEMENT
 *
 * Problem    : An element is a peak when it is greater than both of its
 *              neighbours (out-of-range neighbours count as -infinity).
 *              Print the index of any peak.
 * Input      : n, then n integers
 * Output     : the index of a peak element
 * Idea       : Compare arr[mid] with arr[mid+1] and always walk uphill; the
 *              search space always keeps a peak inside it.
 * Complexity : Time O(log n)   Space O(1)
 */

#include<iostream>


using namespace std;

int main(){

  int n ;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }


  int left = 0 , right = n-1;
  
  while (left < right)
  {

   int mid = left + (right - left )/2;

   if(arr[mid] < arr[mid+1]){
    left = mid + 1;
   }else{
    right = mid;
   }

  }

  cout << left << endl;
  


}