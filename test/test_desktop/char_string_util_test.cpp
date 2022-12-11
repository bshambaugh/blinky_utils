
#include <char_string_util.h>
#include <gtest/gtest.h>
#include <string>

TEST(char_sequence_compare, test_that_two_char_arrays_contain_same_character_sequence_ignoring_null_match_string_and_case) {

  /*
  string expected = "ABBA";
  string actual = "ABBA";
  const char* expected_str = expected.c_str();
  const char* actual_str = actual.c_str();
  */

  const char* expected_str = "ABBA";
  const char* actual_str = "ABBA";

  EXPECT_EQ(char_sequence_compare(expected_str,actual_str),true);
}


TEST(char_sequence_compare, test_that_two_char_arrays_contain_same_character_sequence_ignoring_null_same_string_different_case) {

/*
  string expected = "ABBA";
  string actual = "abba";
  const char* expected_str = expected.c_str();
  const char* actual_str = actual.c_str();
*/

  const char* expected_str = "ABBA";
  const char* actual_str = "abba";

  EXPECT_NE(char_sequence_compare(expected_str,actual_str),true);
}

TEST(char_sequence_compare, test_that_two_char_arrays_contain_same_character_sequence_ignoring_null_different_string) {

/*
  string expected = "abba1";
  string actual = "abba";
  const char* expected_str = expected.c_str();
  const char* actual_str = actual.c_str();
*/

  const char* expected_str = "abba1";
  const char* actual_str = "abba";

  EXPECT_NE(char_sequence_compare(expected_str,actual_str),true);
}

TEST(compareString, test_two_strings_that_are_not_equal) {

  /*
  string expected = "abba1";
  string actual = "abba";
  */

  const char* expected = "abba1";
  const char* actual = "abba";

  
  EXPECT_NE(compareString(expected,actual),true);
}

TEST(compareString, test_two_strings_that_are_equal) {

  /*
  string expected = "abba";
  string actual = "abba";
  */

  const char* expected = "abba";
  const char* actual = "abba";
  
  EXPECT_EQ(compareString(expected,actual),true);
}

TEST(compareString, test_two_strings_that_are_equal_but_not_same_case) {
  /*
  string expected = "abba";
  string actual = "ABBA";
  */

  const char* expected = "abba";
  const char* actual = "ABBA";
  
  EXPECT_NE(compareString(expected,actual),true);
}


TEST(compareString, test_two_strings_that_are_equal_using_cpp) {
  /*
  string expected = "abba";
  string actual = "ABBA";
  */


  std::string expected = "ABBA";
  std::string actual = "ABBA";

 EXPECT_EQ(compareString(expected.c_str(),actual.c_str()),true);
}

TEST(hexCharacterStringToBytes, convert_arrays_to_hex_equal) {

 uint8_t hash[32] = {
    30,  52, 236, 139,   7,  37, 138, 132,
    223,  47,  58, 143, 187, 193, 126, 155,
    209, 126, 101, 164,  33,  84,   7, 143,
    238,  87, 141, 185, 245, 252,  17,  80
 };

  const uint8_t MaxByteArraySize = 32;
  uint8_t byteArray[MaxByteArraySize] = {0};

  /*
  string hashHex = "1e34ec8b07258a84df2f3a8fbbc17e9bd17e65a42154078fee578db9f5fc1150";
  const char* stringHex_str = hashHex.c_str();
  */

  const char* stringHex_str = "1e34ec8b07258a84df2f3a8fbbc17e9bd17e65a42154078fee578db9f5fc1150";

  hexCharacterStringToBytes(byteArray,stringHex_str);
  for(int i=0;i < MaxByteArraySize;i++) {
     ASSERT_EQ(hash[i],byteArray[i]); 
  }
}

TEST(hexCharacterStringToBytes, convert_arrays_to_hex_not_equal_byte_array_different) {

 uint8_t hash[32] = {
    30,  52, 236, 139,   7,  37, 138, 132,
    223,  47,  58, 143, 187, 193, 126, 155,
    209, 126, 101, 164,  33,  84,   7, 143,
    238,  87, 141, 185, 245, 252,  17,  81
 };

  const uint8_t MaxByteArraySize = 32;
  uint8_t byteArray[MaxByteArraySize] = {0};

  /*
  string hashHex = "1e34ec8b07258a84df2f3a8fbbc17e9bd17e65a42154078fee578db9f5fc1150";
  const char* stringHex_str = hashHex.c_str();
  */

  const char* stringHex_str = "1e34ec8b07258a84df2f3a8fbbc17e9bd17e65a42154078fee578db9f5fc1150";

  hexCharacterStringToBytes(byteArray,stringHex_str);
  for(int i=0;i < MaxByteArraySize - 1;i++) {
     EXPECT_EQ(hash[i],byteArray[i]); 
  }
 // EXPECT_NE(hash[MaxByteArraySize],byteArray[MaxByteArraySize]);
  EXPECT_NE(hash[MaxByteArraySize-1],byteArray[MaxByteArraySize-1]);
}


TEST(hexCharacterStringToBytes, convert_arrays_to_hex_not_equal_hex_string_different_last_byte_last_nibble) {

 uint8_t hash[32] = {
    30,  52, 236, 139,   7,  37, 138, 132,
    223,  47,  58, 143, 187, 193, 126, 155,
    209, 126, 101, 164,  33,  84,   7, 143,
    238,  87, 141, 185, 245, 252,  17,  80
 };

  const uint8_t MaxByteArraySize = 32;
  uint8_t byteArray[MaxByteArraySize] = {0};

 /*
  string hashHex = "1e34ec8b07258a84df2f3a8fbbc17e9bd17e65a42154078fee578db9f5fc1151";
  const char* stringHex_str = hashHex.c_str();
*/

  const char* stringHex_str = "1e34ec8b07258a84df2f3a8fbbc17e9bd17e65a42154078fee578db9f5fc1151";

  hexCharacterStringToBytes(byteArray,stringHex_str);
  for(int i=0;i < MaxByteArraySize - 1;i++) {
     EXPECT_EQ(hash[i],byteArray[i]); 
  }
//  EXPECT_NE(hash[MaxByteArraySize],byteArray[MaxByteArraySize]);
    EXPECT_NE(hash[MaxByteArraySize-1],byteArray[MaxByteArraySize-1]);
}

TEST(hexCharacterStringToBytes, convert_arrays_to_hex_not_equal_hex_string_different_last_byte_2nd_to_last_nibble) {

 uint8_t hash[32] = {
    30,  52, 236, 139,   7,  37, 138, 132,
    223,  47,  58, 143, 187, 193, 126, 155,
    209, 126, 101, 164,  33,  84,   7, 143,
    238,  87, 141, 185, 245, 252,  17,  80
 };

  const uint8_t MaxByteArraySize = 32;
  uint8_t byteArray[MaxByteArraySize] = {0};

  /*
  string hashHex = "1e34ec8b07258a84df2f3a8fbbc17e9bd17e65a42154078fee578db9f5fc1160";
  const char* stringHex_str = hashHex.c_str();
  */

  const char* stringHex_str = "1e34ec8b07258a84df2f3a8fbbc17e9bd17e65a42154078fee578db9f5fc1160";

  hexCharacterStringToBytes(byteArray,stringHex_str);
  for(int i=0;i < MaxByteArraySize - 1;i++) {
     EXPECT_EQ(hash[i],byteArray[i]); 
  }
 // EXPECT_NE(hash[MaxByteArraySize],byteArray[MaxByteArraySize]);
  //  EXPECT_NE(hash[31]],byteArray[31]);
    EXPECT_NE(hash[MaxByteArraySize-1],byteArray[MaxByteArraySize-1]);
}