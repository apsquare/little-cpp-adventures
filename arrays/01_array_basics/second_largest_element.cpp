/*
 * SECOND LARGEST ELEMENT
 *
 * Problem    : Given an array of n integers, print the second largest
 *              distinct value.
 * Input      : n, then n integers
 * Output     : the second largest value, or a message when it does not exist
 * Idea       : One pass holding both the largest and the second largest seen
 *              so far.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>
#include<climits>


using namespace std;

int main(){

  int n ;
  cout << "Enter the number of elements" << endl;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int largest = INT_MIN;
  int secondLargest = INT_MIN;
  for(int i=0;i<n;i++){
    if(arr[i] > largest){
      secondLargest = largest;
      largest = arr[i];
    }else if(arr[i] > secondLargest && arr[i] <largest){
      secondLargest = arr[i];
    }
  }
  if(secondLargest == INT_MIN){
    cout << "no second largest " << endl;
    return 0 ;
  }
  cout << secondLargest << endl;
}