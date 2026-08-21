/*
 * SEARCH IN A ROTATED SORTED ARRAY
 *
 * Problem    : A sorted array of distinct integers has been rotated at some
 *              unknown pivot. Print the index of the target, or -1 if it is
 *              absent.
 * Input      : n and target on the first line, then n integers
 * Output     : the index of the target, else -1
 * Idea       : At every step one half is guaranteed sorted; check whether
 *              the target lies inside that sorted half and discard the other
 *              one.
 * Complexity : Time O(log n)   Space O(1)
 */

#include<iostream>

using namespace std;

int main(){
  int n ,target;
  cin >> n >> target;
  int arr[n]; 
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int left =0 , right = n-1;
  while (left <= right)
  {
    int mid = left + (right- left)/2;

    if(arr[mid] == target){
      cout << mid << endl;
      return 0;
    }

    if(arr[left] <= arr[mid]){
      if(arr[left] <= target && target <= arr[mid]){
        right = mid -1;
      }else{
        left = mid + 1;
      }
    }else{
      if(arr[mid] <= target && arr[right] >= target){
        left = mid + 1;
      }else{
        right = mid -1;
      }
    }

  


  }
    cout << -1 << endl;
  

  
  
  


  


}
