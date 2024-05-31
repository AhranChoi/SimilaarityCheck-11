#include <string>

using std::string;

class SimilarityChecker {
private:
	const int _LENGTH_MAX_POINT = 60;
	const int _ZERO_POINT = 0;

public:
	int checkLength(string inputA, string inputB) {
		int aLength = inputA.length();
		int bLength = inputB.length();
		if (isSameStringLength(aLength, bLength)) return _LENGTH_MAX_POINT;

		if (aLength > bLength) {
			if (aLength >= bLength * 2) return _ZERO_POINT;
		}
		else if (bLength >= aLength * 2) return _ZERO_POINT;

		return getPartialLengthPoint(aLength, bLength);
	}

private:
	bool isSameStringLength(int inputALength, int inputBLength)
	{
		return inputALength == inputBLength;
	}

	bool isMoreThanDoubleLength(int inputALength, int inputBLength)
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
