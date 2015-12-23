// DynamicPlanning.cpp : Defines the entry point for the console application.
//
//DPの練習としてフィボナッチ数列の計算を行う

/*
　「フィボナッチ数列」とは，「前の２つの数を加えると次の数になる」という数列です。
 　ただし，１番目と２番目の数は両方とも１です。
 　http://www.suguru.jp/Fibonacci/
*/

#include "stdafx.h"
#include <iostream>
#include <cstdint>

typedef unsigned int u32;

//普通の再帰
namespace normal {
	void clear() {}
	int fib(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return fib(n - 1) + fib(n - 2);
	}
}


//メモ探索
namespace memo {
	bool isMemo[256] = { false };
	u32 memo[256] = { 0 };

	void clear() {
		memset(isMemo, 0, sizeof(isMemo));
		memset(memo, 0, sizeof(memo));
	}

	u32 fib(int n) {
		if (isMemo[n])
			return memo[n];
		u32 ans = 0;
		if (n == 0)
			ans = 0;
		else if (n == 1)
			ans = 1;
		else {
			ans = fib(n - 1) + fib(n - 2);
		}
		isMemo[n] = true;
		memo[n] = ans;
		return ans;
	}
}

//漸化式
namespace zanka {
	u32 dp[256] = { 0 };

	void clear() {
		memset(dp, 0, sizeof(dp));
	}

	u32 fib(int n) {
		for (int N = 0; N <= n; N++) {
			if (N == 0) {
				dp[N] = 0;
			}
			else if (N == 1) {
				dp[N] = 1;
			}
			else {
				dp[N] = dp[N - 1] + dp[N - 2];
			}
		}
		return dp[n];
	}
}

//using namespace normal;
//using namespace memo;
using namespace zanka;

int main()
{
	int testValue[] = {
#if 0
		3,
		4,
		5,
		10,
		20,
		30,
		//40,
#else
		200
#endif
	};
	int testNum = sizeof(testValue) / sizeof(testValue[0]);
	for (int i = 0; i < testNum; i++) {
		clear();
		std::cout << testValue[i] << " : " << fib(testValue[i]) << std::endl;
	}
    return 0;
}

