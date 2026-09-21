#include<iostream>
#include<string>

//! Problem: Given a string containing only '(' and ')', return the minimum number of parentheses you must add to make the string valid.




using namespace std;

int main(){
  string str;
  getline(cin,str);
  int n = str.length();


  int open = 0; //? This will represent the number of parenthesis that stayed opened at the end 
  int required = 0; //? This will represent the numeber of opening parenthesis that will re required at the end 

  for(int i=0;i<n;i++){
    if(str[i] == '('){
      open++;
    }

    if(str[i] == ')'){
      if(open > 0 ){   //? "())" --> One of the open parenthesis already got closed
        open--;
      }else{
        required++;  //? "))(" --> This will required two not 0 parenthesis
      }
    }

  }

  cout << open + required << endl;

}



