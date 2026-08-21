/*
 * FIND THE MINIMUM IN A ROTATED SORTED ARRAY
 *
 * Problem    : A sorted array of distinct integers has been rotated at some
 *              unknown pivot. Print the smallest element.
 * Input      : n, then n integers
 * Output     : the smallest element
 * Idea       : Compare arr[mid] with arr[right]: if it is larger the minimum
 *              must lie to the right, otherwise mid could still be the
 *              minimum.
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

  int left =0 , right = n-1;
  while (left < right)
  {
    int mid = left + (right-left)/2;

   if(arr[mid] > arr[right]){
    left = mid + 1;
   }else{
    right = mid;
   }
    
  }
   

  cout << arr[left] << endl;
  

  
  
  


  


}
