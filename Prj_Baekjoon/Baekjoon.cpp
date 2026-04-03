#include "Baekjoon.h"

void Baekjoon::MaximumValue() {
	int maxValue = -1;
	int maxValueIndex = 0;

	int buffer;
	for (int i = 1; i < 10; ++i) {
		std::cin >> buffer;
		if (maxValue < buffer) {
			maxValue = buffer;
			maxValueIndex = i;
		}
	}

	std::cout << maxValue << std::endl << maxValueIndex << std::endl;
	return;
}

void Baekjoon::BalancedWorld()
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

		std::cout << (isBalanced == true ? "yes" : "no") << std::endl;
	}
}

void Baekjoon::FindWhoDidNotDoHomework() {
	bool arrCheck[30] = { false };

	uint8_t buffer = 0;
	for (uint8_t i = 0; i < 28; ++i) {
		std::cin >> buffer;
		arrCheck[buffer - 1] = true;
	}

	for (uint8_t i = 0; i < 30; ++i) {
		if (arrCheck[i] == false) {
			std::cout << i + 1 << std::endl;
		}
	}
	return;
}

void Baekjoon::ParenthesisStringProblem()
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
}

void Baekjoon::CountingSpecificInteger() {
	uint16_t length = 0;
	std::cin >> length;

	int16_t* arr = new int16_t[length];
	for (uint16_t i = 0; i < length; ++i) {
		std::cin >> arr[i];
	}

	int16_t targetValue = -1;
	std::cin >> targetValue;

	uint16_t count = 0;
	for (uint16_t i = 0; i < length; ++i) {
		if (arr[i] == targetValue) {
			++count;
		}
	}

	std::cout << count << std::endl;

	delete[] arr;
	return;
}

void Baekjoon::FindMinMaxValue() {
	int32_t min = INT32_MAX;
	int32_t max = INT32_MIN;

	uint32_t length = -1;
	std::cin >> length;

	int32_t buffer;
	for (uint32_t i = 0; i < length; ++i) {
		std::cin >> buffer;
		if (buffer < min) {
			min = buffer;
		}
		if (buffer > max) {
			max = buffer;
		}
	}

	std::cout << min << " " << max << std::endl;
}

void Baekjoon::StackAction()
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
}

void Baekjoon::QueueAction()
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
}
