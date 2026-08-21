/*
 * SELECTION SORT
 *
 * Problem    : Sort an array of n integers in ascending order.
 * Input      : n, then n integers
 * Output     : the sorted array, one element per line
 * Idea       : Find the smallest element in the unsorted part and swap it
 *              into position i.
 * Complexity : Time O(n^2)   Space O(1)   Not stable
 */

#include<iostream>


using namespace std;

//? Selection Sort 
//*Find he smallest element and swap it with arr[i]

int main(){

  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  for(int i=0;i<n;i++){
    int minIndex = i;
    for(int j=i ;j<n;j++){
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }
   
    }
       int temp = arr[i];
       arr[i] = arr[minIndex];
       arr[minIndex] = temp;
  }

  for(int i=0;i<n;i++){
    cout << arr[i] << endl;
  }

}