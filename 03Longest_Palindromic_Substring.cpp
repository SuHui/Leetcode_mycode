// Longest_Palindromic_Substring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using std::string;
using std::endl;

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

string expendAroundCenter(string s, int c1, int c2)
{
	int n = s.length();
	int l = c1;
	int r = c2;
	while (l>=0 && r<=n-1 && s[l]==s[r])
	{
		l--;
		r++;
	}
	return s.substr(l+1,r-1-l);
}


string longsetPalindromeSimple(string s)
{
	int len = s.length();
	if (len == 0) return "";
	string longest = s.substr(0,1);
	for (int i = 0; i < len-1; i++)
	{
		string p1 = expendAroundCenter(s,i,i);
		if (p1.length() > longest.length())
		{
			longest = p1;
		}
		string p2 = expendAroundCenter(s,i,i+1);
		if (p2.length() > longest.length())
		{
			longest = p2;
		}
	}
	return longest;
}




int _tmain(int argc, _TCHAR* argv[])
{
	string str = "abccbd";
	std::cout<<longestPalindromDP(str);
	std::cout<<endl;
	std::cout<<longsetPalindromeSimple(str);
	return 0;
}

