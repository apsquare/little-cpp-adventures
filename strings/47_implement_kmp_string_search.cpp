#include <iostream>
#include <string>
#include <vector>

using namespace std;

//! Problem: Given two strings text and pattern, find the index of the first occurrence of pattern inside text using KMP.

int main(){

    string text, pattern;

    getline(cin, text);
    getline(cin, pattern);

    int m = pattern.length();

    // STEP 1: Create LPS array
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while(i < m){

        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{

            if(len > 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }


    // STEP 2: Use LPS array for KMP search

    i = 0;          // pointer for text
    int j = 0;      // pointer for pattern

    while(i < text.length()){

        if(text[i] == pattern[j]){
            i++;
            j++;

            // Entire pattern matched
            if(j == m){
                cout << "Pattern found at index: " << i - j << endl;
                return 0;
            }
        }
        else{

            // Some characters had already matched
            if(j > 0){
                j = lps[j - 1];
            }

            // Nothing had matched
            else{
                i++;
            }
        }
    }

    cout << "Pattern not found" << endl;

    return 0;
}