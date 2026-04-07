#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>

namespace Baekjoon {
	/// <summary>
	/// https://www.acmicpc.net/problem/1010
	/// </summary>
	class BridgeConstruction
	{
	public:
		int main();
	private:
		/// <summary>
		/// <paramref name="n"/>개의 숫자중에서 <paramref name="r"/>개의 수를 선택하는 조합의 개수
		/// </summary>
		/// <returns>조합의 개수</returns>
		uint32_t GetCombinationCount(uint32_t n, uint32_t r);
	};

	/// <summary>
	/// https://www.acmicpc.net/problem/2562
	/// </summary>
	class MaximumValue
	{
	public:
		int main();
	};

	/// <summary>
	/// https://www.acmicpc.net/problem/4949
	/// </summary>
	class BalancedWorld
	{
	public:
		int main();
	};

	/// <summary>
	/// https://www.acmicpc.net/problem/5597
	/// </summary>
	class FindWhoDidNotDoHomework
	{
	public:
		int main();
	};

	/// <summary>
	/// https://www.acmicpc.net/problem/9012
	/// </summary>
	class ParenthesisStringProblem
	{
	public:
		int main();
	};

	/// <summary>
	/// https://www.acmicpc.net/problem/10807
	/// </summary>
	class CountingSpecificInteger
	{
	public:
		int main();
	};

	/// <summary>
	/// https://www.acmicpc.net/problem/10818
	/// </summary>
	class FindMinMaxValue
	{
	public:
		int main();
	};

	/// <summary>
	/// https://www.acmicpc.net/problem/10828
	/// </summary>
	class StackAction
	{
	public:
		int main();
	};

	/// <summary>
	/// https://www.acmicpc.net/problem/10845
	/// </summary>
	class QueueAction
	{
	public:
		int main();
	};
}