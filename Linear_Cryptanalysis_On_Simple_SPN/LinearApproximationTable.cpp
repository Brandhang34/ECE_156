#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

// Given S BOX from the problem
unsigned char sbox[] = {0x8, 0x4, 0x2, 0x1, 0xc, 0x6, 0x3, 0xd, 0xa, 0x5, 0xe, 0x7, 0xf, 0xb, 0x9, 0x0};

// S BOX from the SPN Networks and Linear Cryptanlysis Theory Discussion
/* unsigned char sbox[] = {0xe, 0x4, 0xd, 0x1, 0x2, 0xf, 0xb, 0x8, 0x3, 0xa, 0x6, 0xc, 0x5, 0x9, 0x0, 0x7}; */

const int SIZE_BOX = sizeof(sbox);

string linearApprox(int input_int, int output_int)
{
  int total = 0;
  for (int i = 0; i < SIZE_BOX; ++i)
  {
      // get input and output of our equations
      int input_masked = i & input_int;
      int output_masked = sbox[i] & output_int;
      // if both input and outpt mased is = 0, then increment the total
      if (__builtin_popcount(input_masked) % 2 == __builtin_popcount(output_masked) % 2)
          total += 1;
  }
  return to_string(total);
}

int main()
{
  cout << "   ";
  for (int i = 0; i < SIZE_BOX; i++){ cout <<setw(2) << i << " "; }
  cout << endl;
  for (int row = 0; row < SIZE_BOX; ++row)
  {
      cout << setw(2) << row << " ";
      for (int col = 0; col < SIZE_BOX; ++col)
      {
          cout << setw(2)  << linearApprox(row, col) << " ";
      }
      cout << endl;
  }
  return 0;
}
