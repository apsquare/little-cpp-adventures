/*
 * MERGE SORT
 *
 * Problem    : Sort an array of n integers in ascending order.
 * Input      : n, then n integers
 * Output     : the sorted array, one element per line
 * Idea       : Divide the array in half, sort both halves recursively, then
 *              merge the two sorted halves through a temporary array.
 * Complexity : Time O(n log n)   Space O(n)   Stable
 */

#include<iostream>

using namespace std;


void merge(int arr[], int left , int right , int mid){
  int temp[right -left +1]; //temporary sorted array 


  int i = left ;
  int j = mid +1;
  int k =0;

  while(i <= mid && j <= right){
    if(arr[i] <= arr[j]){
      temp[k++] = arr[i]; 
      i++;
    }else{
      temp[k++] = arr[j];
      j++;
    }
  }

  while (i<=mid)
  {
    temp[k++] = arr[i++];
  }

  while (j <=right)
  {
    temp[k++] = arr[j++];
  }
  

  for(int x=0;x<k;x++){
    arr[left + x] = temp[x]; // putting the sorted elements in the original array 
  }
  


}

void mergeSort(int arr[], int left ,int right){
  if(left >= right){
    return ;
  }

  int mid = left + (right -left)/2;
  mergeSort(arr,left,mid);//Splitting the left part 
  mergeSort(arr,mid+1,right); //Splitting the right part
  merge(arr,left,right,mid);
}

int main(){


  int n;
  cin >>n ;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int left = 0;
  int right = n-1;
  mergeSort(arr,left,right);
  
  for(int i=0;i<n;i++){
    cout << arr[i] << endl;
  }
  


}