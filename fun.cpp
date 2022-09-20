#include "fun.h"
/* //TESTING WITH VECTORS, Was having some issues with arrays and wanted to see if the code itself was the problem or if I was just stupid
int readInFile(int* &org, int &SIZE){
  ifstream inFile;
  inFile.open("text.txt");
  if(!inFile.is_open()){
    cout << "File not found" << endl;
    return 1;
  }

  int num;
  vector<int> v1;
  while(inFile >> num){
    v1.push_back(num);
  }
  SIZE = v1.size();
  org = new int[SIZE];
  for(int i = 0; i < SIZE; i++){
    org[i] = v1[i];
  }
  
  return 0;
}*/

int readInFile(int* &org, int &SIZE){
  ifstream inFile;
  inFile.open("text.txt");
  if(!inFile.is_open()){
    cout << "FILE NOT FOUND" << endl;
    return 1;
  }

  int num;
  SIZE = 100;
  org = new int[SIZE];
  for(int i = 0; i < SIZE; i++){
    inFile >> num;
    org[i] = num;
  }
  return 0;
}

int checkNum(int *org, int numSearched, int SIZE){
  for(int i = 0; i < SIZE; i++){
    if(org[i] == numSearched){
      return i;
    }
  }
  return -1;
}

void addNum(int* &org, int newNum, int &SIZE){
  int* newArray = new int[SIZE+1];
  for(int i = 0; i < SIZE; i++){
    newArray[i] = org[i];
  }
  newArray[SIZE] = newNum;
  SIZE++;
  int* temp = org;
  org = newArray;
  delete[] temp;
}

void delNum(int* &org, int index, int &SIZE){
  int* newArray = new int[SIZE-1];
  for(int i = 0; i < index; i++){
    newArray[i] = org[i];
  }
  for(int i = index+1; i < SIZE; i++){
    newArray[i-1] = org[i];
  }
  SIZE--;
  int* temp = org;
  org = newArray;
  delete[] temp;
}