#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string AlphaToNum(string alpha){
  string Nums;
  int strLength = alpha.length();
  map<char, char> NumToA = {
      {'a', '2'}, {'b', '2'}, {'c', '2'}, {'d', '3'}, {'e', '3'}, {'f', '3'},
      {'g', '4'}, {'h', '4'}, {'i', '4'}, {'j', '5'}, {'k', '5'}, {'l', '5'},
      {'m', '6'}, {'n', '6'}, {'o', '6'}, {'p', '7'}, {'q', '7'}, {'r', '7'},
      {'s', '7'}, {'t', '8'}, {'u', '8'}, {'v', '8'}, {'w', '9'}, {'x', '9'},
      {'y', '9'}, {'z', '9'}};
  for (int i = 0; i < strLength; i++){
    Nums += NumToA[alpha[i]];
  }
  return Nums;
}

bool ValidInput(string input) {
  int strLength = input.length();
  if (strLength == 8 && input[3] == '-'){
    for(int i = 0; i < strLength; i++){
      if(input[i] == '1' || input[i] == '0'){
        return false;
      }
    }
    return true;
  } 
  else{
    return false;
  }
}

int main() {
string lines, input, userKeys;
cin >> input;
int strLength = input.length();


  if (ValidInput(input)) {
    ifstream fin("ShortList.txt");
    ofstream fout("output.txt");
    vector<string> word3;
    vector<string> word4;
    vector<string> word7;
    int count3 = 0, count4 = 0, count7 = 0;
    string user3, user4, user7;


    for (long i = 0; i < strLength; i++) {
      if (i < 3) {
        user3 += input[i];
      } else if (i > 3) {
        user4 += input[i];
      }
    }
    user7 = user3 + user4;


    while (getline(fin, lines)) {
      if (user3 == AlphaToNum(lines)){
        count3++;
        word3.push_back(lines);
      }
      if (user4 == AlphaToNum(lines)){
        count4++;
        word4.push_back(lines);
      }
      if (user7 == AlphaToNum(lines)){
        count7++;
        word7.push_back(lines);
      }
    }


    for (int i = 0; i < count3; i++){
      for (int j = 0; j < count4; j++){
        fout << word3.at(i) << " " << word4.at(j) << endl;
      }
    }
    for (int i = 0; i < count7; i++){
      fout << word7.at(i) << endl;
    }


    if (count3 == 0 && count4 == 0 && count7 == 0){
      fout << "No results!" << endl;
    }
  }
  else{
    cout << "Invalid phone number" << endl;
  }


  return 0;
}