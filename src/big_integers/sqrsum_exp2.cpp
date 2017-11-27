#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

int main()
{
  ZZ acc, val;

  acc = 0;

  cout << "[*] This program reads a list of integers \n    and output the sum of their squares.\n";

  while (cin >> val)
    acc += val*val;

  cout << acc << "\n";
}
