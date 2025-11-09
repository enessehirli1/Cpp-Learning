#include <gtest/gtest.h>
#include "../S15.cpp"

class FruitTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Test öncesi gerekli kurulumlar buraya
    }
};

// Constructor ve Type enum testi
TEST_F(FruitTest, ConstructorSetsTypeCorrectly) {
    Fruit apple(Fruit::apple);
    Fruit banana(Fruit::banana);
    Fruit cherry(Fruit::cherry);

    EXPECT_EQ(apple.getType(), Fruit::apple);
    EXPECT_EQ(banana.getType(), Fruit::banana);
    EXPECT_EQ(cherry.getType(), Fruit::cherry);
}

// getType() metodu testi
TEST_F(FruitTest, GetTypeReturnsCorrectType) {
    Fruit apple(Fruit::apple);
    EXPECT_EQ(apple.getType(), Fruit::apple);
}

// getPercentageEaten() metodu testi
TEST_F(FruitTest, GetPercentageEatenInitialValueIsZero) {
    Fruit apple(Fruit::apple);
    EXPECT_EQ(apple.getPercentageEaten(), 0);
}

// isCherry() metodu testleri
TEST_F(FruitTest, IsCherryReturnsTrueForCherry) {
    Fruit cherry(Fruit::cherry);
    EXPECT_TRUE(cherry.isCherry());
}

TEST_F(FruitTest, IsCherryReturnsFalseForNonCherry) {
    Fruit apple(Fruit::apple);
    Fruit banana(Fruit::banana);
    
    EXPECT_FALSE(apple.isCherry());
    EXPECT_FALSE(banana.isCherry());
    vstest.console.exe Debug\S15.exe /TestAdapterPath:.\packages\GoogleTest*
}