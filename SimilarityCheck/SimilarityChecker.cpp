#include <string>

using std::string;

class SimilarityChecker {
public:
	int compareStringSimilarity(string inputA, string inputB) {
		int lengthScore = compareStringLength(inputA, inputB);
		int alphaScore = compareStringAlphabet(inputA, inputB);
		return lengthScore + alphaScore;
	}

	int compareStringLength(string inputA, string inputB) {
		LengthInputA = inputA.size();
		LengthInputB = inputB.size();
		if (isSameStringLength()) return _LENGTH_MAX_POINT;
		if (isMoreThanDoubleLength()) return _LENGTH_MIN_POINT;
		return getPartialLengthPoint();
	}

	int compareStringAlphabet(string inputA, string inputB) {
		int alphaListA[26] = { 0 };
		int alphaListB[26] = { 0 };
		existAlphabetList(inputA, alphaListA);
		existAlphabetList(inputB, alphaListB);

		int cntA = countAlphabetList(alphaListA);
		int cntB = countAlphabetList(alphaListB);
		int sameCnt = countSameAlphabet(alphaListA, alphaListB);
		int totalCnt = cntA + cntB - sameCnt;
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

	void existAlphabetList(std::string& inputStr, int alphaList[26])
	{
		int charIdx = 0;
		for (int i = 0; i < inputStr.length(); i++) {
			charIdx = inputStr[i] - 'A';
			alphaList[charIdx]++;
		}
	}

	int countAlphabetList(int alphaCnt[26]) {
		int result = 0;
		for (int i = 0; i < 26; i++) {
			if (alphaCnt[i] != 0) result++;
		}
		return result;
	}

	int countSameAlphabet(int alphaListA[26], int alphaListB[26])
	{
		int result = 0;
		for (int i = 0; i < 26; i++) {
			if (alphaListA[i] != 0 && alphaListB[i] != 0) result++;
		}
		return result;
	}
};
