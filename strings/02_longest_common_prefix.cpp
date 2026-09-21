#include<iostream>
#include<string>

using namespace std;

//! Question: Given an array of strings, find the longest prefix common to all strings.
//! ["flower", "flow", "flight"] → "fl"


int main(){

  int n;
  cin >> n;
  string arr[n];
  cin.ignore(); //? This may leave a '\n' in the buffer.
  for(int i=0;i<n;i++){
    string s;
    getline(cin,s);
    arr[i] = s;
  }
  


  int longestPrefix = arr[0].length();

  for(int i=0;i<n;i++){
    int currentLongest = 0;

    while(currentLongest < arr[i].length() && currentLongest < arr[0].length() && arr[i][currentLongest] == arr[0][currentLongest]){
      currentLongest++;
    }

    longestPrefix = min(longestPrefix,currentLongest);

  }


  string result = "";

  for(int i=0;i<longestPrefix ;i++){
    result += arr[0][i];
  }

  cout << result << endl;

}
