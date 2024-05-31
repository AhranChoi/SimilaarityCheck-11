#include <string>

using std::string;

class SimilarityChecker {
public:
	int compareStringLength(string inputA, string inputB) {
		LengthInputA = inputA.size();
		LengthInputB = inputB.size();
		if (isSameStringLength()) return _LENGTH_MAX_POINT;
		if (isMoreThanDoubleLength()) return _LENGTH_MIN_POINT;
		return getPartialLengthPoint();
	}

	int checkAlphabet(string inputA, string inputB) {
		int alphaCntA[26] = { 0 };
		int alphaCntB[26] = { 0 };

		int charIdx = 0;
		for (int i = 0; i < inputA.length(); i++) {
			charIdx = inputA[i] - 'A';
			alphaCntA[charIdx]++;
		}

		for (int i = 0; i < inputB.length(); i++) {
			charIdx = inputB[i] - 'A';
			alphaCntB[charIdx]++;
		}

		int aCnt = 0;
		int bCnt = 0;
		int sameCnt = 0;
		
		for (int i = 0; i < 26; i++) {
			if (alphaCntA[i] != 0) aCnt++;
			if (alphaCntB[i] != 0) bCnt++;
			if (alphaCntA[i] != 0 && alphaCntB[i] != 0) sameCnt++;
		}

		int totalCnt = aCnt + bCnt - sameCnt;
		int score = sameCnt * 40 / totalCnt;

		return score;
	}

private:
	const int _LENGTH_MAX_POINT = 60;
	const int _LENGTH_MIN_POINT = 0;
	const int _ALPHABET_MAX_POINT = 40;
	int LengthInputA;
	int LengthInputB;

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
