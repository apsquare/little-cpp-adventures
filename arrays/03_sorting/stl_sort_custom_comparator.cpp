/*
 * STL SORT WITH A CUSTOM COMPARATOR
 *
 * Problem    : Given n pairs (first, second), sort them by the first value
 *              in ascending order, and break ties by the second value in
 *              descending order.
 * Input      : n, then n pairs of integers
 * Output     : the sorted pairs, one per line
 * Idea       : Pass a comparator to std::sort that returns true when a must
 *              come before b.
 * Complexity : Time O(n log n)   Space O(1)
 */

#include<iostream>
#include<algorithm>


using namespace std;



bool comparator(pair <int ,int> a , pair<int,int> b){
  if(a.first != b.first){ 
    return a.first < b.first;//* If the first elements are same we sort in ascending order otherwise we sort in descending order
  }else{
    return a.second > b.second;
  }
}

int main(){

  int n;
  cin >> n;
  pair<int,int> arr[n];
  for(int i=0;i<n;i++){
    int first , second;
    cin >> first >> second;
    arr[i] = {first,second};
  }


  sort(arr, arr + n ,comparator);

  for(int i=0;i<n;i++){
    cout << arr[i].first << " " << arr[i].second << endl;
  }

  cout << endl;














}
