// Longest_Palindromic_Substring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using std::string;

string  longestPalindromDP(string s)
{
     int n = s.length();
	 int longestBegin = 1;
	 int maxLen = 1; 
	 bool table[1000][1000] = {false};
	 for (int i = 0; i < n; i++)
	 {
		 table[i][i] = true;
	 }
	 for (int i = 0; i < n-1; i++)
	 {
		 if (s[i] == s[i+1])
		 {
			table[i][i+1] = true;
			longestBegin = i;
			maxLen = 2;
		 }
	 }
	 for (int len = 3; len <= n; len++)
	 {
		 for (int i = 0; i < n-len+1; i++)
		 {
			 int j = i+len-1;
			 if (s[i] == s[j] && table[i+1][j-1])
			 {
				 table[i][j] = true;
				 longestBegin = i;
				 maxLen = len;
			 }
		 }
	 }
	 return s.substr(longestBegin, maxLen);

}

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "abccbd";
	std::cout<<longestPalindromDP(str);
	return 0;
}

