#include <string>

using std::string;

class SimilarityChecker {
public:
	int checkLength(string inputA, string inputB) {
		int ret = 0;
		if (inputA.length() == inputB.length()) return 60;
		
		int gap;
		if (inputA.length() > inputB.length()) {
			gap = (inputA.length() - inputB.length());
			ret = ((inputB.length() - gap) * 60) / inputB.length();
		}
		else {
			gap = (inputB.length() - inputA.length());
			ret = ((inputA.length() - gap) * 60) / inputA.length();
		}

		return ret;
	}
};
