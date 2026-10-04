#include <iostream>
#include <string>
#include <vector>

using namespace std;

//* LPS array says that from here the strign is same as it is from the begining , So no need to start searching from the beginning again

int main(){

    string pattern;
    getline(cin, pattern);

    int n = pattern.length();

    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;


//? For every index i, find the length of the longest prefix that is also a suffix ending at i.
    while(i < n){

        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
//? The prefix I'm currently trying didn't work, but maybe a smaller prefix can work. 
            if(len > 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

    for(int value : lps){
        cout << value << " ";
    }

    cout << endl;

    return 0;
}