/*
 * THREE SUM (sorting + two pointers)
 *
 * Problem    : Given an array of n integers, find every unique triplet
 *              whose values sum to 0. No duplicate triplets, order of the
 *              output does not matter.
 * Input      : n, then n integers
 * Output     : each triplet on its own line
 * Idea       : Sort, fix one element, then two-pointer the rest of the
 *              array for the pair that completes the sum. Sorting puts
 *              duplicates next to each other so they can be skipped.
 * Complexity : Time O(n^2)   Space O(1) beyond the answer
 * TODO       : the triplets are collected in the vector but never printed,
 *              so the program produces no output. Loop over triplets at the
 *              end and print each one.
 */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// Given an integer array nums, find all unique triplets [nums[i], nums[j], nums[k]] such that i, j, and k are different indices and:
// nums[i] + nums[j] + nums[k] = 0
// The answer must not contain duplicate triplets.
// The order of the triplets in the output does not matter.



int main(){


  //? Taking input
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  vector<vector<int>> triplets;
  

  //?We will first sort the array so that the duplicates appear next to each other and we can directly skip them 
  //?Also the question states that the order does not matter 
  sort(arr,arr+n);


  //? i will be the index of the element that is fixed
  for(int i=0;i<n;i++){

    if( i> 0 && arr[i] == arr[i-1]) continue; //? In case the current element and the previous elements are the same we direct skip it 
  

    int left = i + 1;
    int right = n - 1;

    while (left < right){
      int sum = arr[i] + arr[left] + arr[right];

      if(sum == 0){
        vector<int> triplet = {arr[i],arr[left],arr[right]};
        triplets.push_back(triplet);
        left ++;
        right --;

        while (left < right && arr[left] == arr[left-1]) //? This will skip ant duplicate elements for the left element
        { 
          left ++;
        }

        while(left < right && arr[right] == arr[right+1]){ // ? This will skip any duplicate elements on for the right element 
          right--;
        }


      }else if(sum < 0){
        left ++;
      }else{
        right --;
      }

    }
    
  }

  return 0;


}