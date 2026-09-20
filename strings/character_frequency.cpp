

#include<iostream>
#include<string>
using namespace std;

int main(){

  string s;
  getline(cin,s);
  int n = s.length();

 
  int freq[256] = {0};
  

  for(int i=0;i<n;i++){
    freq[s[i]]++;
  }


  for(int i=0;i<256;i++){
    if(freq[i] != 0){
      cout << char(i) << " : " << freq[i] << endl;
    }
  }

}
