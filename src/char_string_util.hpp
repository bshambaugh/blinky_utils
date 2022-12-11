#include <cstring>
#include <iostream>
using namespace std;

#pragma once

bool char_sequence_compare(const char a[],const char b[]);

bool compareString(string s1, string s2);

uint8_t nibble(char c);

void hexCharacterStringToBytes(uint8_t *byteArray, const char *hexString);

// Modified https://stackoverflow.com/questions/15050766/comparing-the-values-of-char-arrays-in-c#15050807
// compares two character arrays to see if they have the same sequence of characters
// I might need to modify this to return a pointer or something...
// this may be able to exist in its own file.
bool char_sequence_compare(const char a[],const char b[]){
    if(strlen(a) > strlen(b)) {
      for(int i=0;a[i]!='\0';i++){
         if(a[i]!=b[i])
             return false;
      }
    } else {
       for(int i=0;b[i]!='\0';i++){
         if(a[i]!=b[i])
             return false;
       }
    }
    return true;
}

bool compareString(string s1, string s2)
{  
      if(strcmp(s1.c_str(),s2.c_str()) == 0) {
           return true;
      } else {
           return false;
      }
}

// source: https://forum.arduino.cc/t/hex-string-to-byte-array/563827
// reply: johnwasser, Dec '18post #4
//
// this may be able to exist in its own file.
uint8_t nibble(char c)
{
  if (c >= '0' && c <= '9')
    return c - '0';

  if (c >= 'a' && c <= 'f')
    return c - 'a' + 10;

  if (c >= 'A' && c <= 'F')
    return c - 'A' + 10;

  return 0;  // Not a valid hexadecimal character
}

// source: https://forum.arduino.cc/t/hex-string-to-byte-array/563827
// reply: johnwasser, Dec '18post #4
// this may be able to exist in its own file.
void hexCharacterStringToBytes(uint8_t *byteArray, const char *hexString)
{
  bool oddLength = strlen(hexString) & 1;

  uint8_t currentByte = 0;
  uint8_t byteIndex = 0;

 /// uint8_t byteArray;

  for (uint8_t charIndex = 0; charIndex < strlen(hexString); charIndex++)
  {
    bool oddCharIndex = charIndex & 1;

    if (oddLength)
    {
      // If the length is odd
      if (oddCharIndex)
      {
        // odd characters go in high nibble
        currentByte = nibble(hexString[charIndex]) << 4;
      }
      else
      {
        // Even characters go into low nibble
        currentByte |= nibble(hexString[charIndex]);
        byteArray[byteIndex++] = currentByte;
        currentByte = 0;
      }
    }
    else
    {
      // If the length is even
      if (!oddCharIndex)
      {
        // Odd characters go into the high nibble
        currentByte = nibble(hexString[charIndex]) << 4;
      }
      else
      {
        // Odd characters go into low nibble
        currentByte |= nibble(hexString[charIndex]);
        byteArray[byteIndex++] = currentByte;
        currentByte = 0;
      }
    }
  }
}

