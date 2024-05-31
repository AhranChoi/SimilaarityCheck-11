#include <string>

using std::string;

class SimilarityChecker {
private:
	const int _LENGTH_MAX_POINT = 60;

public:
	int checkLength(string inputA, string inputB) {
		if (isSameStringLength(inputA.length(), inputB.length())) return _LENGTH_MAX_POINT;
		return getPartialLengthPoint(inputA.length(), inputB.length());
	}

private:
	bool isSameStringLength(int inputALength, int inputBLength)
	{
		return inputALength == inputBLength;
	}

	int getPartialLengthPoint(int inputALength, int inputBLength)
	{
		int gap = std::abs(inputALength - inputBLength);
		int shortLength = (inputALength > inputBLength) ? inputBLength : inputALength;	
		return ((shortLength - gap) * _LENGTH_MAX_POINT) / shortLength;
	}
};
