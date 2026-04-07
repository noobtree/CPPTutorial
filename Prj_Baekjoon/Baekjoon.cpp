#include "Baekjoon.h"

int Baekjoon::BridgeConstruction::main()
{
	// 테스트 케이스 개수 입력 받기
	int testCase = 0;
	std::cin >> testCase;

	uint32_t* combinationCounts = new uint32_t[testCase];

	for (int i = 0; i < testCase; ++i)
	{
		// 입력 받기
		int n = 0;
		int m = 0;
		std::cin >> n >> m;

		// m_C_n	m개 중에서 n개를 중복 미포함 하여 뽑는 경우의 수
		uint32_t buffer = GetCombinationCount(m, n);
		combinationCounts[i] = buffer;
	}

	for (int i = 0; i < testCase; ++i)
	{
		std::cout << combinationCounts[i] << std::endl;
	}

	delete[] combinationCounts;
	return 0;
}

/// <summary>
/// <paramref name="n"/>개의 숫자중에서 <paramref name="r"/>개의 수를 선택하는 조합의 개수
/// </summary>
/// <returns>조합의 개수</returns>
uint32_t Baekjoon::BridgeConstruction::GetCombinationCount(uint32_t n, uint32_t r)
{
	if (n < r)
	{
		throw std::out_of_range("'r' must be equal or less than 'n'");
	}

	if (r > n / 2)
	{
		r = n - r;
	}
	if (n == 1 || r == 0)
	{
		return 1;
	}
	static int combinationMemory[30][30];

	if (combinationMemory[n - 1][r - 1] == 0)
	{
		uint32_t include_N = GetCombinationCount(n - 1, r - 1);
		uint32_t exclude_N = GetCombinationCount(n - 1, r);

		combinationMemory[n - 1][r - 1] = include_N + exclude_N;
	}

	return combinationMemory[n - 1][r - 1];
}

int Baekjoon::MaximumValue::main()
{
	int maxValue = -1;
	int maxValueIndex = 0;

	int buffer;
	for (int i = 1; i < 10; ++i)
	{
		std::cin >> buffer;
		if (maxValue < buffer)
		{
			maxValue = buffer;
			maxValueIndex = i;
		}
	}

	std::cout << maxValue << std::endl << maxValueIndex << std::endl;
	return 0;
}

int Baekjoon::BalancedWorld::main()
{
	std::vector<std::string> sentences;
	while (true)
	{
		std::string token;
		std::getline(std::cin, token, '\n');

		if (token == ".")
		{
			break;
		}

		sentences.push_back(token);
	}

	for (const std::string& sentence : sentences)
	{
		bool isBalanced = true;
		std::stack<char> parenthesis;

		for (int i = 0; i < sentence.size(); ++i)
		{
			if (sentence[i] == '(' || sentence[i] == '[')
			{
				parenthesis.push(sentence[i]);
			}
			if (sentence[i] == ')')
			{
				if ((parenthesis.empty() == false) && (parenthesis.top() == '('))
				{
					parenthesis.pop();
				}
				else
				{
					isBalanced = false;
					break;
				}
			}
			if (sentence[i] == ']')
			{
				if ((parenthesis.empty() == false) && (parenthesis.top() == '['))
				{
					parenthesis.pop();
				}
				else
				{
					isBalanced = false;
					break;
				}
			}
		}

		std::cout << (isBalanced && parenthesis.empty() ? "yes" : "no") << std::endl;
	}
	return 0;
}

int Baekjoon::FindWhoDidNotDoHomework::main()
{
	bool arrCheck[30] = { false };

	int buffer = 0;
	for (int i = 0; i < 28; ++i)
	{
		std::cin >> buffer;
		arrCheck[buffer - 1] = true;
	}

	for (int i = 0; i < 30; ++i)
	{
		if (arrCheck[i] == false)
		{
			std::cout << i + 1 << std::endl;
		}
	}
	return 0;
}

int Baekjoon::ParenthesisStringProblem::main()
{
	int t = 0;
	std::cin >> t;

	bool* arrResult = new bool[t];
	for (int i = 0; i < t; ++i)
	{
		std::string parenthesisString;
		std::cin >> parenthesisString;

		std::stack<char> parenthesis = std::stack<char>();

		for (int j = 0; j < parenthesisString.size(); ++j)
		{
			if (parenthesisString[j] == '(')
			{
				parenthesis.push('(');
			}
			if (parenthesisString[j] == ')')
			{
				if (parenthesis.empty() == true)
				{
					parenthesis.push(')');
					break;
				}
				else
				{
					parenthesis.pop();
				}
			}
		}

		arrResult[i] = parenthesis.empty();
	}

	for (int i = 0; i < t; ++i)
	{
		std::cout << (arrResult[i] == true ? "YES" : "NO") << std::endl;
	}

	delete[] arrResult;
	return 0;
}

int Baekjoon::CountingSpecificInteger::main()
{
	uint16_t length = 0;
	std::cin >> length;

	int16_t* arr = new int16_t[length];
	for (uint16_t i = 0; i < length; ++i)
	{
		std::cin >> arr[i];
	}

	int16_t targetValue = -1;
	std::cin >> targetValue;

	uint16_t count = 0;
	for (uint16_t i = 0; i < length; ++i)
	{
		if (arr[i] == targetValue)
		{
			++count;
		}
	}

	std::cout << count << std::endl;

	delete[] arr;
	return 0;
}

int Baekjoon::FindMinMaxValue::main()
{
	int32_t min = INT32_MAX;
	int32_t max = INT32_MIN;

	uint32_t length = -1;
	std::cin >> length;

	int32_t buffer;
	for (uint32_t i = 0; i < length; ++i)
	{
		std::cin >> buffer;
		if (buffer < min)
		{
			min = buffer;
		}
		if (buffer > max)
		{
			max = buffer;
		}
	}

	std::cout << min << " " << max << std::endl;
	return 0;
}

int Baekjoon::StackAction::main()
{
	int commandCount;
	std::cin >> commandCount;
	std::cin.ignore();

	std::string* arrCommand = new std::string[commandCount];

	for (int i = 0; i < commandCount; ++i)
	{
		std::string line;
		std::getline(std::cin, line, '\n');

		arrCommand[i] = line;
	}

	std::stack<int> buffer;

	for (int i = 0; i < commandCount; ++i)
	{
		std::stringstream ss(arrCommand[i]);
		std::string token;
		std::getline(ss, token, ' ');

		if (token == "push")
		{
			std::getline(ss, token, '\n');
			int pushValue = std::stoi(token);

			buffer.push(pushValue);
			continue;
		}
		if (token == "pop")
		{
			int popValue = -1;
			if (buffer.size() > 0)
			{
				popValue = buffer.top();
				buffer.pop();
			}
			std::cout << popValue << std::endl;
			continue;
		}
		if (token == "size")
		{
			std::cout << buffer.size() << std::endl;
			continue;
		}
		if (token == "empty")
		{
			std::cout << (buffer.empty() == true ? 1 : 0) << std::endl;
			continue;
		}
		if (token == "top")
		{
			int popValue = -1;
			if (buffer.size() > 0)
			{
				popValue = buffer.top();
			}
			std::cout << popValue << std::endl;
			continue;
		}
	}

	delete[] arrCommand;
	return 0;
}

int Baekjoon::QueueAction::main()
{
	int commandCount;
	std::cin >> commandCount;
	std::cin.ignore();

	std::string* arrCommand = new std::string[commandCount];

	for (int i = 0; i < commandCount; ++i)
	{
		std::string line;
		std::getline(std::cin, line, '\n');

		arrCommand[i] = line;
	}

	std::queue<int> buffer;

	for (int i = 0; i < commandCount; ++i)
	{
		std::stringstream ss(arrCommand[i]);
		std::string token;
		std::getline(ss, token, ' ');

		if (token == "push")
		{
			std::getline(ss, token, '\n');
			int pushValue = std::stoi(token);

			buffer.push(pushValue);
			continue;
		}
		if (token == "pop")
		{
			int popValue = -1;
			if (buffer.size() > 0)
			{
				popValue = buffer.front();
				buffer.pop();
			}
			std::cout << popValue << std::endl;
			continue;
		}
		if (token == "size")
		{
			std::cout << buffer.size() << std::endl;
			continue;
		}
		if (token == "empty")
		{
			std::cout << (buffer.empty() == true ? 1 : 0) << std::endl;
			continue;
		}
		if (token == "front")
		{
			int popValue = -1;
			if (buffer.size() > 0)
			{
				popValue = buffer.front();
			}
			std::cout << popValue << std::endl;
			continue;
		}
		if (token == "back")
		{
			int recentValue = -1;
			if (buffer.size() > 0)
			{
				recentValue = buffer.back();
			}
			std::cout << recentValue << std::endl;
			continue;
		}
	}

	delete[] arrCommand;
	return 0;
}
