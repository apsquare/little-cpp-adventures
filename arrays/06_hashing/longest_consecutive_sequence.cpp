/*
 * LONGEST CONSECUTIVE SEQUENCE
 *
 * Problem    : Given an unsorted array of integers, print the length of the
 *              longest run of consecutive numbers. They do not have to be
 *              adjacent in the array.
 * Input      : n, then n integers
 * Output     : the length of the longest consecutive sequence
 * Idea       : Put everything in a set and only start counting from a value
 *              whose predecessor is missing, so each sequence is walked
 *              exactly once.
 * Complexity : Time O(n) average   Space O(n)
 */

#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;



int main(){


  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }


  unordered_set<int> seen;

  for(int i=0;i<n;i++){
    seen.insert(arr[i]);
  }

  int maxLength = 0;

  for(int i=0;i<n;i++){
    int current = arr[i];
    if(seen.find(current-1) == seen.end()){ //*Start the count only if this element was not a prt of some previous subarray
      int length = 1;
      while (seen.find(current + 1) != seen.end())
      {
        length++;
        current++;
      }
      maxLength = max(maxLength,length);
      
    }
  }

  cout << maxLength << endl;



}