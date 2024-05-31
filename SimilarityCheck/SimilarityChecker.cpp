#include <string>
#include <set>

using std::string;
using std::set;

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
		set<char> alphaSetA;
		set<char> alphaSetB;

		convertStringToCharSet(inputA, alphaSetA);
		convertStringToCharSet(inputB, alphaSetB);
		return calcAlphabetScore(alphaSetA, alphaSetB);
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

	void convertStringToCharSet(std::string& str, std::set<char>& charSet)
	{
		for (auto ch : str) {
			if (charSet.find(ch) == charSet.end()) charSet.insert(ch);
		}
	}

	int countSameCharInSets(set<char>& charSetA, set<char>& charSetB) {
		int result = 0;
		for (auto ch : charSetA) {
			if (charSetB.find(ch) != charSetB.end()) result++;
		}
		return result;
	}

	int calcAlphabetScore(set<char>& charSetA, set<char>& charSetB)
	{
		int sameCnt = countSameCharInSets(charSetA, charSetB);
		int totalCnt = charSetA.size() + charSetB.size() - sameCnt;
		return sameCnt * _ALPHABET_MAX_POINT / totalCnt;
	}
};
