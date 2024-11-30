#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;



int expand_from_center(string &s){
  int length = s.length();

  int start = 0, max = 1;

  for(int i = 0; i < length; i++){
    for(int j = 0; j <=1; j++{
	int l = i;
	int h = i + j;
	while(l >= 0 && h < length && s[l] == s[h]){
	  int curr = h- l + 1;
	  if(curr > max){
	    start = l;
	    max = curr;
	  }
	  l--;
	  h++;
	}
	
      }

  }
    //print sub from start to max indexes
  return 0; 
}
