#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//? Problem: Given an array of strings, group together strings that are anagrams of each other.
//? Input: ["eat", "tea", "tan", "ate", "nat", "bat"]
//? Output: [["eat","tea","ate"],["tan","nat"],["bat"]]

int main(){

 int n;
 cin >> n;
 cin.ignore();
 vector<string> input_array(n) ;
 for(int i=0;i<n;i++){
  string word ;
  getline(cin,word);
  input_array[i] = word;
 }

 unordered_map<string,vector<string>> groups;

 for(int i=0;i<n;i++){
  string key = input_array[i];

  sort(key.begin(),key.end()); //? The anagrams will get sorted to the same word and will ultimatey have the same hash

  groups[key].push_back(input_array[i]);
 }

 for(auto &group : groups){

  for(string word : group.second){ //? Looping over an unordered map will return a key value pair
    cout << word << " ";
  }
  cout << endl;
   
 }
 




}