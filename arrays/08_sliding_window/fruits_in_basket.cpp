#include<iostream>
#include<unordered_map>

using namespace std;


//! Question: You are given an integer array fruits, where fruits[i] represents the type of fruit on the ith tree. You have two baskets, and each basket can hold only one type of fruit, but can hold any number of fruits of that type. Starting from any tree, you must pick exactly one fruit from every consecutive tree while moving to the right. You must stop when you reach a fruit type that cannot fit into either basket. Return the maximum number of fruits you can collect.

int main(){


  int n;
  cin >> n;
  int fruits[n];
  for(int i=0;i<n;i++){
    cin >> fruits[i];
  }
 
  
  int left = 0;
  int right =0 ;
  int max_fruits_collected = 0;
  unordered_map<int,int> freq;

  while(right < n){
    freq[fruits[right]]++;

    while(freq.size() > 2){
      freq[fruits[left]]--;
      if(freq[fruits[left]] ==0 ){
        freq.erase(fruits[left]);
      }
      left++;
    }

    max_fruits_collected = max(max_fruits_collected,right-left+1);
    right++;
  }

  cout << max_fruits_collected << endl;

}