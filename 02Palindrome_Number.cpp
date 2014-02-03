// Palindrome_Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>

//基本思路直接求反转的数字 没有考虑反过来是否会溢出
int Palindrome(int x)
{
	assert(x>=0);
	int m=0;
	int n=0;
	while (x>0)
	{
		n=x%10;
		x=x/10;
		m=m*10+n;
	}
	return m;
}

//后来思考采用比较首尾法
bool isPalindrome(int x)
{
	int div = 1;
	while(x /div >= 10)
	{
		div*=10;
	}
	while(x !=0)
	{
		int l=x/div;
		int r=x%10;
		if(l != r) return false;
		x=(x%div)/10;
		div/=100;
	}
	return true;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	std::cin>>x;
	//std::cout<<Palindrome(x);
	if(isPalindrome(x)==true)
		std::cout<<"s";
	return 0;
}

