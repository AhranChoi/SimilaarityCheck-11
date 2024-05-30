#include <string>

#include "pch.h"
#include "../SimilarityCheck/SimilarityChecker.cpp"

using std::string;

TEST(SimilarityCheckerTest, CheckLengthWithSameLengthStrings) {
	SimilarityChecker checker;
	string inputA = "ASD";
	string inputB = "DSA";

	EXPECT_EQ(checker.checkLength(inputA, inputB), 60);
}
