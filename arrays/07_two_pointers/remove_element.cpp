#include<iostream>
#include<utility>

using namespace std;


//! Question: Given an integer array nums and an integer val, remove all occurrences of val from nums in-place and return the number of elements that are not equal to val. If there are k remaining elements, the first k positions of the array must contain those elements; anything after the first k positions does not matter. The relative order of the remaining elements may be changed. Do not create another array for the result, and aim for O(n) time and O(1) extra space.


int main(){

  int n ,val;
  cin >> n;
  int nums[n];
  for(int i=0;i<n;i++){
    cin >> nums[i];
  }
  cin >> val;

  if(n==0){
    return 0;
  }

  int left =0 ; //? This is where the next element need to be placed 
  int right = 0; //? This scans the remaining array

  while (left < n && right < n)
  {
    if(nums[right] != val){
      nums[left] = nums[right]; //? When ever you find a value that is not val move it to the left
      left++;
    }
    right++;


  }

  cout << left << endl;
  







}