#include <string>

#include "pch.h"
#include "../SimilarityCheck/SimilarityChecker.cpp"

using std::string;

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, CheckLength) {
	EXPECT_EQ(checker.compareStringLength("ASD", "DSA"), 60);
	EXPECT_EQ(checker.compareStringLength("A", "BB"), 0);
	EXPECT_EQ(checker.compareStringLength("AAABB", "BAA"), 20);
	EXPECT_EQ(checker.compareStringLength("AA", "AAE"), 30);
	EXPECT_EQ(checker.compareStringLength("A", "AAAAA"), 0);
}

TEST_F(SimilarityCheckerFixture, CheckSameAlphabetAll) {
	EXPECT_EQ(checker.checkAlphabet("A", "A"), 40);
	EXPECT_EQ(checker.checkAlphabet("A", "AAAA"), 40);
	EXPECT_EQ(checker.checkAlphabet("ASD", "DSA"), 40);
	EXPECT_EQ(checker.checkAlphabet("A", "BB"), 0);
	EXPECT_EQ(checker.checkAlphabet("AAABB", "BA"), 40);
	EXPECT_EQ(checker.checkAlphabet("AA", "AAE"), 20);
}
