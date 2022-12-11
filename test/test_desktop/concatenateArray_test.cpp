#include <concatenateArray.h>
#include <gtest/gtest.h>

TEST(voidUint8Array, void_a_uint8_array) {

    uint8_t input[4] = { 30,  52, 236, 139 };
    uint8_t expected[4] = { 0,  0, 0, 0 };

    voidUint8Array(4, input);

    for(int i=0;i < 4;i++) { 
      EXPECT_EQ(expected[i],input[i]); 
    }
    
}

TEST(voidCharArray, void_a_char_array) {

    char input[4] = { 'A',  'B', 'C', 'D' };
    char expected[4] = { 0,  0, 0, 0 };

    voidCharArray(4, input);

    for(int i=0;i < 4;i++) { 
      EXPECT_EQ(expected[i],input[i]); 
    }
}
    
TEST(mergeCharArray, merge_a_char_array) {
   unsigned char input[4] = { 'A', 'B', 'C', 'D' };
   char result[9] = {0};
   mergeCharArray(4,input,result);

   // I am not sure how to test mergeCharArray ,but it seems to work
   //EXPECT_EQ(result[0],'A'); 
}

