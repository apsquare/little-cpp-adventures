#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
//! Problem: Given a string s, rearrange its characters so that characters with a higher frequency appear before characters with a lower frequency.

//! Input:
//! "tree"
//! Output:
//! "eert" or eetr

int main(){

  string s;
  getline(cin,s);

  unordered_map<char,int> freq;
  vector<pair<char,int>> pair_vector;

  for(auto ch : s){
    freq[ch] ++;
  }

  for(auto pair : freq){
    pair_vector.push_back(pair);
  }

  sort(pair_vector.begin(),pair_vector.end(), [](auto &a , auto &b){
    return b.second < a.second;
  });

  string result = "";
  for(auto p : pair_vector){
    result += string(p.second,p.first);
  }
  
  cout << result << endl;




  
}