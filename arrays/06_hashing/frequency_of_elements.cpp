/*
 * FREQUENCY OF EVERY ELEMENT
 *
 * Problem    : Given an array of n integers, print the frequency of every
 *              distinct element.
 * Input      : n, then n integers
 * Output     : one "value frequency" pair per line (unordered)
 * Idea       : Count into an unordered_map, then walk the map.
 * Complexity : Time O(n) average   Space O(n)
 */

#include<iostream>
#include<unordered_map>

using namespace std;


int main(){


  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }



  unordered_map<int,int> freq   ;
  for(int i=0;i<n;i++){
    freq[arr[i]]++;
  }

  for(auto elem : freq){
    cout << elem.first << " " << elem.second << endl;
  }





  



}