#include <string>

#include "pch.h"
#include "../SimilarityCheck/SimilarityChecker.cpp"

using std::string;

TEST(SimilarityCheckerTest, TC0) {
	SimilarityChecker checker;
	string inputA = "ASD";
	string inputB = "DSA";
	int ret = checker.checkLength(inputA, inputB);
	EXPECT_EQ(ret, 60);
}
