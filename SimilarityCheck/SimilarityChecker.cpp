#include <string>

using std::string;

class SimilarityChecker {
public:
	int checkLength(string inputA, string inputB) {
		if (inputA.length() == inputB.length()) return 60;
		return 0;
	}
};