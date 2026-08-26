#include<iostream>
#include<unordered_map>

//! Question: Given an integer array arr and an integer k, print the number of distinct elements in every contiguous subarray of size k. For example, arr = [1,2,1,3,4,2,3], k = 4 → output 3 4 4 3 because the windows are [1,2,1,3], [2,1,3,4], [1,3,4,2], and [3,4,2,3].

using namespace std;


int main(){

  //? Taking input
  int n ,k;
  std::cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    std::cin >> arr[i]; 
  }
  std::cin >> k;

  unordered_map<int,int> freq; //? This will store the frequency of the elements in the current window

  int left = 0;
  int right = 0;  

  while(right < n){
    freq[arr[right]] ++;

    if(right - left + 1 == k){
      cout << freq.size() << " ";
      freq[arr[left]] --;

      if(freq[arr[left]] == 0){
        freq.erase(arr[left]); //? If the frequency of the element has become 0. we can remove this from the map 
      };
      left ++;
    }

     right++;
  }


  cout << endl;

}