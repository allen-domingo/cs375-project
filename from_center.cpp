#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



string expand_from_center(string &s1, string &s2){
  int length1 = s1.length(), length2 = s2.length();
  string rev_s2 = s2;
  // cout << endl << "s1: " << s1 << ", s2: " << s2;
  reverse(rev_s2.begin(), rev_s2.end());
   string longestPal = "";

  int start = 0, max = 0;
 
  for(int i = 0; i < length1; i++){
    if(i == length2){
      break;
    }
    for(int j = 0; j <=1; j++){

     
	int l = i;
	int h = i + j;
	while(l >= 0 && h < length1 && s1[l] == s1[h]){
	  int curr = h-l+1;
	  string candidate = s1.substr(l,h-l +1);
	  if(rev_s2.find(candidate) != string::npos &&  curr > max){
	    start = l;
	    max = curr;
	    longestPal = candidate;

	  }
   
	  l--;
	  h++;
	}
    }
  }
  if(longestPal.size() == 0){
    return  "NONE";
  }
    return longestPal; 
}

int main(){
  vector<string> tests1;
  vector<string> tests2;
  
  ifstream file1("tests1.txt");
  ifstream file2("tests2.txt");
  string curr_line;
  if(file1.is_open()){
    while(getline(file1, curr_line)){
      stringstream stream(curr_line);
      string s;
      while(stream >> s){
	tests1.push_back(s);
      }    	       
    }   
  }
  if(file2.is_open()){
    while(getline(file2, curr_line)){
      stringstream stream(curr_line);
      string s;
      while(stream >> s){
	tests2.push_back(s);
      }    	       
    }   
  }
  string s1;
  string s2;
  clock_t start = clock();
  for(int i = 0; i < tests1.size(); i++){
    s1 = tests1[i];
    s2 = tests2[i];
    // expand_from_center(s1,s2);
       cout << "exp from center longest:" <<  expand_from_center(s1,s2) << endl;
  }
  cout << "Running time: " << clock() - start << endl;
  return 0;
    
}

 
