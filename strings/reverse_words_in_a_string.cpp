#include<iostream>
#include<string>
#include<vector>

//! Reverse the order of words in a string.
//! Input:  "the sky is blue"
//! Output: "blue is sky the"

using namespace std;

int main(){

  string s;
  getline(cin,s);
  vector<string>words;
  int str_length = s.length();


  int temp =0 ;
 

  //? Collected all the words based on spaces between them
  string currentWord = "";
  while(temp < str_length ){
    if(s[temp] != ' '){
      currentWord += s[temp];
    }else if(currentWord != "") {
        words.push_back(currentWord);
        currentWord = "";
    }

    temp++;
  }

  if(currentWord != ""){
    words.push_back(currentWord);
  }

  string result = "";
  int n = words.size();
  for(int i=n-1;i>=0;i--){
    result = result + words[i];
    if(i != 0){
      result += " ";
    }
  }

  cout << result << endl;


 



}