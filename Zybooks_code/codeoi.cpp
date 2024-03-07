#include <iostream>
using namespace std;

void PrintSelectedNumbers(int numCount) {
   int i;
   int number;

   for (i = 0; i < numCount; ++i) {
      cin >> number;
      if ((number % 4) == 0) {
         cout << number << endl;
      }
   }
}

int main() {
   int numCount = 7;

   PrintSelectedNumbers(numCount);

   return 0;
}