#include <string>

#include "pch.h"
#include "../SimilarityCheck/SimilarityChecker.cpp"

using std::string;

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, CheckLength) {
	EXPECT_EQ(checker.checkLength("ASD", "DSA"), 60);
	EXPECT_EQ(checker.checkLength("A", "BB"), 0);
	EXPECT_EQ(checker.checkLength("AAABB", "BAA"), 20);
	EXPECT_EQ(checker.checkLength("AA", "AAE"), 30);
}
