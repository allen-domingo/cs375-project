#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;



string expand_from_center(string &s1, string &s2){
  int length1 = s1.length(), length2 = s2.length();
  string rev_s2 = s2;
  reverse(rev_s2.begin(), rev_s2.end());
   string longestPal = "";

  int start = 0, max = 0;
 
  for(int i = 0; i < length1; i++){

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
    return  "";
  }
    return longestPal; 
}

int main(){
  ifstream file("tests.txt");
  string s1 = "abcdef";
  string s2 = "gfedcba";

  cout << "exp from center longest:" <<  expand_from_center(s1,s2) << endl;
  return 0;
    
}

 
