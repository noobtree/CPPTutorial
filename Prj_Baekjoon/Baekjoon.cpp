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
