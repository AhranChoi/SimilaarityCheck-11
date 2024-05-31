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
	EXPECT_EQ(checker.compareStringAlphabet("A", "A"), 40);
	EXPECT_EQ(checker.compareStringAlphabet("A", "AAAA"), 40);
	EXPECT_EQ(checker.compareStringAlphabet("ASD", "DSA"), 40);
	EXPECT_EQ(checker.compareStringAlphabet("A", "BB"), 0);
	EXPECT_EQ(checker.compareStringAlphabet("AAABB", "BA"), 40);
	EXPECT_EQ(checker.compareStringAlphabet("AA", "AAE"), 20);
}

TEST_F(SimilarityCheckerFixture, CompareSimilarity) {
	EXPECT_EQ(checker.compareStringSimilarity("A", "A"), 100);
	EXPECT_EQ(checker.compareStringSimilarity("A", "AAAA"), 40);
	EXPECT_EQ(checker.compareStringSimilarity("ASD", "DSA"), 100);
	EXPECT_EQ(checker.compareStringSimilarity("A", "BB"), 0);
	EXPECT_EQ(checker.compareStringSimilarity("ABD", "BA"), 56);
	EXPECT_EQ(checker.compareStringSimilarity("AA", "AAE"), 50);
}
