#include<iostream>
#include<string>

using namespace std;

//! Problem:
//! Given a string s, determine whether it can be constructed by taking one of its substrings and repeating that substring multiple times.

//! Input:
//! s = "abab"
//! Output: true
//! Explanation: "ab" repeated 2 times.

#include <iostream>
#include <string>

using namespace std;

//! LeetCode 459 - Repeated Substring Pattern
//! Check whether the entire string can be formed by
//! repeating one of its substrings multiple times.

int main(){

    string s;
    getline(cin, s);

    int n = s.length();

    for(int k = 1; k <= n / 2; k++){

      //?  If the length of the substring is not a divisor of length of string we cannot form the sting from the substring 
        if(n % k != 0){
            continue;
        }

        string substring = s.substr(0, k);
        bool valid = true;

        //? Check whether substring repeats throughout s.  ababab --> ab + ab + ab | k = 2 , 3 % 2 = 1
        for(int j = 0; j < n; j++){
            if(s[j] != substring[j % k]){
                valid = false;
                break;
            }
        }

        if(valid){
            cout << "true" << endl;
            return 0;
        }
    }

    cout << "false" << endl;

    return 0;
}
