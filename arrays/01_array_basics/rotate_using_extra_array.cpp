/*
 * ROTATE AN ARRAY LEFT BY K (extra array)
 *
 * Problem    : Given an array of n integers and a number k, rotate the array
 *              to the left by k positions.
 * Input      : n, then n integers, then k
 * Output     : the rotated array
 * Idea       : Copy into a second array with rotated[i] = arr[(i + k) % n].
 * Complexity : Time O(n)   Space O(n)
 */

#include<iostream>

using namespace std;

int main(){

    int n , k;
    cin >> n ;
    int arr[n];
    for(int i=0;i<n;i++){
      cin >> arr[i];
    }

    cin >>k ;
    k = k % n;


    int rotated[n];

    for(int i=0;i<n;i++){
      rotated[i] = arr[(i+k)%n];
    }

    for(int i=0;i<n;i++){
      cout << rotated[i] << " ";
    }

    cout << endl;


}