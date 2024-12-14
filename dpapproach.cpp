#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string lcps(const string& A, const string& B) {
    int n = A.size();
    int m = B.size();

    // DP-Table to store lengths of longest common suffixes
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));

    int maxLength = 0;
    int endIndexA = 0;

    // itereate through DP-Table
    for (int n = 1; n <= A.size(); ++n) {
        for (int m = 1; m <= B.size(); ++m) {
            if (A[n - 1] == B[m - 1]) {  //if matching char is found, value = whatever is in the slot diagonally up and to the left
                dp[n][m] = dp[n - 1][m - 1] + 1;
                int len = dp[n][m];

                // extract the substring
                string potentialPalindrome = A.substr(n - len, len);

                // palindrome checl
                string reversed = potentialPalindrome;
                reverse(reversed.begin(), reversed.end()); //reverse function from Algorithms library

                if (potentialPalindrome == reversed && len > maxLength) {
                    maxLength = len;
                    endIndexA = n;
                }
            }
        }
    }
    return A.substr(endIndexA - maxLength, maxLength);
}

// print the DP-Table (testing purposes)
void printDPTable(const vector<vector<int>>& dp) {
    for (const auto& row : dp) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
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
       cout << "Dynamic Programming: " <<  lcps(s1,s2) << endl;
  }
  cout << "Running time: " << clock() - start << endl;
}
