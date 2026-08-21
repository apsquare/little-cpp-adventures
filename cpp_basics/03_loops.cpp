/*
 * C++ BASICS - loops and patterns
 *
 * Topic  : for / while loops and nested loops.
 * Covers : 1..100, multiplication table, sum of naturals, factorial, digit
 *          count, reverse a number, palindrome number, prime check, primes
 *          upto n, Fibonacci and star patterns.
 * Active : the last block prints the sum of squares 1^2 + ... + 5^2.
 */

#include<iostream>

using namespace std;

int main(){
  // Print numbers from 1 to 100
  // for (int i =0 ;i<100 ;i++){
  //   cout << i+ 1 << endl;
  // }

  // for(int i=100 ;i>=1 ;i--){
  //   cout << i << endl;
  // }

  // int num ;
  // cout << "Enter the number " << endl;
  // cin >> num ;
  // for(int i=1;i<=10;i++){
  //   cout << num << "\t*\t" <<  i << "\t" << num * i   << endl;
  // }

  // int num  ; 
  // cout << "Enter a natural number" << endl;
  // cin >> num;
  // int sum =0 ;
  // cout << "The sum of the first " << num << " natural numbers is ";
  // for(int i=1;i<=num;i++){
  //   sum += i;
  // }
  // cout << sum << endl;

  // Factorial
  // int num ;
  // cout << "Enter a natural number" << endl;
  // cin >> num;

  // int fac = 1;
  // for(int i=1;i<=num;i++){
  //   fac *= i;
  // }
  // cout <<fac << endl;

  // Number of digits
  // int num ;
  // cout << "Enter a natural number" << endl;
  // cin >> num;
  // int count =1 ;
  // while(num > 9){
  //   count ++ ;
  //   num = num /10;
  // }
  // cout << "There are total " << count << " digits in the number" << endl;

  // Reverse the number
  // int num ;
  // cout << "Enter a number " << endl;
  // cin >> num;
  // int reversedNumber = 0;

  // while(num>0){
  //   reversedNumber = reversedNumber * 10 + num %10 ;
  //   num = num / 10;
  // }

  // cout << "The reversed number is " << reversedNumber << endl;


  // Palindrome check
  // int num ;
  // cout << "Enter a number " << endl;
  // cin >> num;
  // int original = num;
  // int reversedNumber = 0;

  // while(num>0){
  //   reversedNumber = reversedNumber * 10 + num %10 ;
  //   num = num / 10;
  // }

  // reversedNumber == original ? cout << "The number is a palindrome" << endl  : cout <<   "The number is not a palindrome" << endl  ;

  // Check whether the number is prime



  // int num ;
  // cout << "Enter a number " << endl;
  // cin >> num;
  // int factors = 0;
  // for(int i=1;i<=num;i++){
  //   if(num % i == 0){
  //     factors ++;
  //   }
  // }

  // if(factors >2){
  //   cout << "The number is not a prime number."<<endl;
  // }else{
  //   cout << "The number is a prime number." << endl;
  // }


  // int num ;
  // cout << "Enter a number " << endl;
  // cin >> num;
  // for(int j=1;j<=num;j++){
  //   int factors = 0;
  //   int current ;
  //   for(int i=1;i<=j;i++){
  //     if(j % i == 0){
  //       factors ++;
  //     }

  //   }
  //   if(factors == 2){
  //     cout << j <<endl;
  //   }
  // }

  // // Fibonacci series
  // int num ;
  // cout << "Enter a number " << endl;
  // cin >> num;
  // int a = 0 ;
  // int b = 1;
  // for(int i=0;i<num;i++){
  //   cout << a << " ";
  //   int temp = b ;
  //   b = a+ b;
  //   a = temp;
  // }


  // Pattern 1
  // for(int i=1;i<=5;i++){
  //   for(int j=0;j<i;j++){
  //     cout << "* " ; 
  //   }
  //   cout << endl;
  // }

  // Pattern 2
  // for(int i=5;i>=1;i--){
  //   for(int j=i;j>=1;j--){
  //     cout << "* " ; 
  //   }
  //   cout << endl;
  // }


  // Pattern 3
  // for(int i=1;i<=5;i++){
  //   for(int j=1;j<=i;j++){
  //     cout << j << " ";
  //   }
  //   cout << endl;
  // }

  // Pattern 4
  //  for(int i=1;i<=5;i++){
  //   for(int j=1;j<=i;j++){
  //     cout << i << " ";
  //   }
  //   cout << endl;
  // }


  // Pattern 5
  // for(int i=1;i<=5;i++){
  //   for(int j=1;j<=5-i;j++){
  //     cout << " ";
  //   }
  //   for(int j=0;j<(2*i -1) ;j++){
  //     cout << "*";
  //   }
  //   cout << endl;
  // }

  // Challenge
  int sum  =0 ;
  for(int i=1;i<=5;i++){
    
    sum += i * i;
  }
  cout << sum << endl;

}
