#include<iostream>
#include<string>

using namespace std;

//! Problem: You are given a binary string s containing only '0' and '1'.
//! In one operation, you can change '0' to '1' or '1' to '0'.
//! Return the minimum number of operations required to make s alternating.

//! An alternating string has no two adjacent characters equal.

//! "0101" --> even string
//! "1010" --> odd string 

//! Input:  "0100"
//! Output: 1
//! Explanation: Change the last '0' to '1' → "0101"

//! Input:  "1111"
//! Output: 2


//* Think about what character you expect at an even index versus an odd index. 

int main(){

  string str;
  getline(cin,str);
  int n = str.length();

  int even_changes = 0, odd_changes = 0;
  //? Even changes is when the character even index is '0' and odd index is '1'

  //? Counting the number of changes for even string 
  for(int i=0;i<n;i++){
    if(i%2==0){
      if(str[i] != '0'){
        even_changes++;
      }
    }else{
      if(str[i] != '1'){
        even_changes++;
      }
    }
  }

  //? Counting the number of changes for odd string 
  for(int i=0;i<n;i++){
    if(i%2==0){
      if(str[i] != '1'){
        odd_changes++;
      }
    }else{
      if(str[i] != '0'){
        odd_changes++;
      }
    } 
  }


  if(even_changes < odd_changes){
    cout << even_changes << endl;
  }else{
    cout << odd_changes << endl;  
  }





}

