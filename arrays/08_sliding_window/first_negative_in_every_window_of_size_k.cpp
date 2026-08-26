#include<iostream>
#include<queue>
//! Question: Given an integer array arr and an integer k, print the first negative number in every contiguous subarray (window) of size k. If a window contains no negative number, print 0.


//? Question: Given an integer array arr and an integer k, print the first negative number in every contiguous subarray (window) of size k. If a window contains no negative number, print 0.
//? Example: arr = [12, -1, -7, 8, -15, 30, 16, 28], k = 3 → output [-1, -1, -7, -15, -15, 0].


using namespace std;

int main(){

  int n ,k ;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }


  queue<int> negatives; // This sotres the negative index 

  int left = 0;
  int right =0 ;

  while(right < n){
    if(arr[right] < 0){
      negatives.push(right);
    }

    if(right - left + 1 == k){
      if(negatives.empty()){
        cout << 0 << " ";
      }else{
        cout << arr[negatives.front()] << " ";
      }

      //? Remove the negative index if this was at the place of left 
      if(!negatives.empty() && negatives.front() == left){
        negatives.pop();
      }
      left++;

    }

    right ++;


  }

  cout << endl;





}