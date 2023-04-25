#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "fuzztest/fuzztest.h"
#include "gtest/gtest.h"

extern "C" {
  #include "calculator.h"
}

void test_add_commutes(int x, int y) {
   EXPECT_EQ(add(x,y), add(y,x));
}

void test_add_subtract(int x, int y) {
   EXPECT_EQ(subtract(add(x,y),y), x);
}

void test_multiply_commutes(int x, int y) {
   EXPECT_EQ(multiply(x,y), multiply(y,x));
}

void test_cancel_divisor(int x) {
  int product = multiply(x,x);
  EXPECT_EQ(divide(product, x), x);
}

void test_factor_game(int x, int y) {
  EXPECT_EQ(factor_game(x,y), 0);
}

void test_all(int x, int y) {
  int choice = x % 5;

  switch(choice) 
  {
    case 0: test_add_commutes(x, y); break;
    case 1: test_add_subtract(x, y); break;
    case 2: test_multiply_commutes(x, y); break;
    case 3: test_cancel_divisor(x); break;
    case 4: test_factor_game(x, y); break;
  }
}

//FUZZ_TEST(CalculatorFuzzTest, test_add_commutes);
//FUZZ_TEST(CalculatorFuzzTest, test_add_subtract);
//FUZZ_TEST(CalculatorFuzzTest, test_multiply_commutes);
//FUZZ_TEST(CalculatorFuzzTest, test_cancel_divisor);
FUZZ_TEST(CalculatorFuzzTest, test_all);
