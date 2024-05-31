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

TEST(SimilarityCheckerTest, CheckLengthWithDoubleLengthStrings) {
	SimilarityChecker checker;
	string inputA = "ASD";
	string inputB = "DSADSA";

	EXPECT_EQ(checker.checkLength(inputA, inputB), 0);
}

TEST(SimilarityCheckerTest, CheckLengthWithDifferentLengthStrings) {
	SimilarityChecker checker;
	string inputA = "AAAA";
	string inputB = "AAAAAA";

	EXPECT_EQ(checker.checkLength(inputA, inputB), 30);
}
