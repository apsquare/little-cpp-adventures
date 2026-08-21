/*
 * INTERSECTION OF TWO ARRAYS
 *
 * Problem    : Given two integer arrays of the same length n, print the
 *              unique values that appear in both of them.
 * Input      : n, then n integers of the first array, then n integers of the
 *              second
 * Output     : the common values, one per line (unordered)
 * Idea       : Put the first array in a set, then keep the elements of the
 *              second array that are found in it, deduplicating through a
 *              second set.
 * Complexity : Time O(n) average   Space O(n)
 * TODO       : arr2 is declared with size 2 but n values are read into it,
 *              which writes out of bounds. It should be int arr2[n].
 */

#include<iostream>
#include<unordered_set>


using namespace std;


int main(){

  //*Taking input for the two arrays
  int n;
  cin >> n;
  int arr1[n] ,arr2[2];
  for(int i=0;i<n;i++){
    cin >> arr1[i];
  }
  for(int i=0;i<n;i++){
    cin >> arr2[i];
  }


  unordered_set<int>set1;
  unordered_set<int>answer;

  for(int i=0;i<n;i++){
    set1.insert(arr1[i]);
  }

  for(int i=0;i<n;i++){
    if(set1.find(arr2[i]) != set1.end()){
      answer.insert(arr2[i]);
    }
  }

  for(int elem : answer){
    cout << elem << endl;
  }

  


}