/*
 * ALLOCATE MINIMUM NUMBER OF PAGES
 *
 * Problem    : n books with given page counts must be handed to m students
 *              in contiguous blocks. Print the smallest possible value of
 *              the maximum number of pages assigned to a student.
 * Input      : n, then n page counts, then m
 * Output     : the minimised maximum pages
 * Idea       : Binary search the answer between the largest book and the
 *              total pages; for a candidate limit, count how many students
 *              the greedy split needs.
 * Complexity : Time O(n log(sum - max))   Space O(1)
 */

#include<iostream>
#include<algorithm>
#include<numeric>


using namespace std;

// left = 90 because 90 is the minimum possible value for the maximum number of pages assigned to a student.
// right = the sum of all the pages


int distribution_possible(int arr[],int n , int mid   ){
  
  int student = 1;
  int currentPages = 0;

  for(int i=0;i<n;i++){
    if(currentPages + arr[i] <= mid){
      currentPages += arr[i];
    }else{
      student++;
      currentPages = arr[i];
    }
  }
  return student;
}


int main(){

  int n ,m ;
  cin >> n;
  int arr[n];

  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cin >> m;


  int left = *max_element(arr,arr+n);
  int right = accumulate(arr,arr+n,0);
  int answer = right;

  while (left <= right)
  {
    int mid = left + (right-left)/2;
    if(distribution_possible(arr,n,mid) > m){
      left = mid + 1;
    }else{
      right = mid -1 ;
      answer = mid;

    }


  }
  

  cout << answer << endl;


}
