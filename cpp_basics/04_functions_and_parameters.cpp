/*
 * C++ BASICS - functions and parameters
 *
 * Topic   : declaring a function, passing parameters and returning a value.
 * Example : maximum(a, b, c) returns the largest of three integers.
 */

#include<iostream>


using namespace std;


int maximum(int a, int b, int c){
  if(a > b && a > c){
    return a ;
  }else if( b> a && b> c){
    return b;
  }else {
    return c;
  }
}


int main(){

  cout << maximum(10,20,30) << endl;


}