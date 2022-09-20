#include <iostream>
#include <vector>
#include "fun.h"
using namespace std;


int main() {
  int* org;
  int SIZE, num;
  readInFile(org, SIZE);
  for(int i = 0; i < SIZE; i++){
    cout << org[i] << " ";
  }

  cout << "\nWhat number would you like to check for? ";
  cin >> num;
  if(checkNum(org, num, SIZE) == -1){
    cout << "The number does not exist in the array." << endl;
  }else{
    cout << "The number exists at index " << checkNum(org,num, SIZE) << endl;
  }

  cout << "What new number would you like to add? ";
  cin >> num;
  
  addNum(org, num, SIZE);
  
  for(int i = 0; i < SIZE; i++){
    cout << org[i] << " ";
  }

  cout << "\nWhat index would you like to delete? ";
  cin >> num;
  
  delNum(org, num, SIZE);

  for(int i = 0; i < SIZE; i++){
    cout << org[i] << " ";
  }
}