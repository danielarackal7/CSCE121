#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  unsigned int count = 0;
  while (str[count] != '\0') count++;
  return count;
}

unsigned int find(char str[], char character) {
  for (unsigned int i = 0; str[i] != '\0'; i++) {
    if (str[i] == character) return i;
  }
  return length(str);
}

bool equalStr(char str1[], char str2[]) {
  unsigned int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
      if (str1[i] != str2[i]) return false;
      i++;
  }
  return str1[i] == str2[i];
}
