#include<iostream>
#include<string>
#include<unordered_map>


using namespace std;


//! Question: Given two strings s1 and s2, return true if s2 contains any permutation of s1 as a contiguous substring; otherwise return false. A permutation contains the same characters with the same frequencies, but the order may be different. For example, s1 = "ab" and s2 = "eidbaooo" → true because "ba" is a permutation of "ab".


int main (){

  string s1 , s2;
  getline(cin,s1); //Taking input for s1
  getline(cin,s2); //Taking input for s2
  int length1 = s1.length();
  int length2 = s2.length();



  int left =0 ;
  int right =0 ;
  
  unordered_map<int,int> freq1;
  unordered_map<int,int> freq2;

  
  for(char ch : s1){ // Freq of s1
    freq1[ch - 'a']++;
  }


  while(right < length2){

    freq2[s2[right] -'a']++;

    //? Shriking before the check 
    if(right-left+1 > length1){
      freq2[s2[left] - 'a']--;
      left++;
    }

    if(right-left+1 == length1){
      bool same = true;

      for(int i=0;i<26;i++){
        if(freq1[i] != freq2[i]){
          same = false;
          break;
        }
      }

      if(same){
      cout << "same" << endl;
      return 0;
    }

    //? Shrinking after the check 
    //? freq2[s2[left] - 'a']--;
    //? left++;

    }

    
    right++;

  }

  cout << "false" << endl;
 
}