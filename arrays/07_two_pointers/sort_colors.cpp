#include<iostream>
#include<utility>

using namespace std;

int main(){


  //? Here we are using the  The Dutch National Flag
  //? The Dutch National Flag algorithm is a three-pointer technique used when you want to divide an array into three groups in one pass.
  //? low   → where the next 0 should go
  //? mid   → element we're currently checking
  //? high  → where the next 2 should go


  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int left = 0;
  int right = n-1;
  int mid =0; //? Mid should also start with index 0 

  while(mid <= right){
    
    if(arr[mid] == 0){ //? In case the mid has 0 swap it with the left index
      swap(arr[left],arr[mid]);
      left++;
      mid++;
    }else if(arr[mid] == 1 ){
      mid++;
    }else{
      swap(arr[mid],arr[right]);
      right--;
    }

  }


  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }
  cout << endl;








}