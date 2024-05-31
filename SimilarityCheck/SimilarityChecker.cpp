#include <string>

using std::string;

class SimilarityChecker {
private:
	const int _LENGTH_MAX_POINT = 60;
	const int _LENGTH_MIN_POINT = 0;
	int LengthInputA;
	int LengthInputB;

public:
	int checkLength(string inputA, string inputB) {
		LengthInputA = inputA.size();
		LengthInputB = inputB.size();
		if (isSameStringLength()) return _LENGTH_MAX_POINT;
		if (isMoreThanDoubleLength()) return _LENGTH_MIN_POINT;
		return getPartialLengthPoint();
	}

private:
	bool isSameStringLength()
	{
		return LengthInputA == LengthInputB;
	}

	bool isMoreThanDoubleLength()
	{
		if (LengthInputA >= LengthInputB * 2) return true;
		if (LengthInputB >= LengthInputA * 2) return true;
		return false;
	}

	int getPartialLengthPoint()
	{
		int gap = std::abs(LengthInputA - LengthInputB);
		int shortLength = (LengthInputA > LengthInputB) ? LengthInputB : LengthInputA;
		return ((shortLength - gap) * _LENGTH_MAX_POINT) / shortLength;
	}
};
