#include <NTL/ZZ.h>
#include <NTL/vector.h>

using namespace std;
using namespace NTL;

ZZ sum(const Vec<ZZ>& v)
{
  ZZ acc;

  acc = 0;

  // for (long i = 0; i < v.length(); i ++)
  //   acc += v[i];

  // we can index from 1, not 0
  for (long i = 1; i <= v.length(); i ++)
    acc += v(i);

  return acc;
}

int main()
{
  Vec<ZZ> v;
  cin >> v;
  ZZ acc = conv<ZZ>(0);
  acc = sum(v);
  cout << "l1 norm of " << v << " is: \n";
  cout << acc << "\n";

  long n = v.length();



  v.SetLength(2*n);

  long i;
  for (i = 0; i < n; i ++)
    v[n + i] = -1 * v[n - 1 - i];

  cout << "l1 norm of " << v << " is: \n";
  acc = sum(v);
  cout << acc;

}
