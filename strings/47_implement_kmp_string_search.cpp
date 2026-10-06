#include<iostream>
#include<string>

//! Implementing the KMP Algorithm to find a given pattern inside the entered text 
using namespace std;

//* Text    = "ababac"
//* Pattern = "abac"

//* Pattern Index:  0  1  2  3
//* Pattern:        a  b  a  c
//* LPS:            0  0  1  0

int main(){
   string text , pattern;
   getline(cin,text);
   getline(cin,pattern);

   int n = text.length();
   int m = pattern.length();

   vector<int> lps;

   int len = 0;
   int i =1 ;

//*    Creating the lps array
   while(i<m){
    if(pattern[i] == pattern[len]){
        len++;
        lps[i] = len;
        i++;
    }else{
        if(len>0){
            //*Fall back to the next smaller matching prefix-suffix.
            len = lps[len-1];
        }else{
            lps[i] = 0;
            i++;
        }
    }
   }

    //* Using the lps array to apply KMP algorithm 
    int i=0;
    int j =0 ;

    while(i<text.length()){
        if(text[i] == pattern[j]){
            i++;
            j++;
            if(j==m){
                //* We have reached the end of the patter so the patten was found
                cout << "Pattern was found " << endl;
                return 0; 
            }
        }else if(j>0){

//* On mismatch, move j to continue after the last matched part that can be reused as the beginning of the pattern.
            j = lps[j-1];
        }else{
            i++;
        }
    }

    cout << "Pattern was not found " << endl;
    return 0 ;





}
