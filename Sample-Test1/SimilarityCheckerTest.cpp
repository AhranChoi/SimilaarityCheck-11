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
