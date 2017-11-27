#include <NTL/ZZ_p.h>

using namespace std;
using namespace NTL;

void add(Vec<ZZ_p>& x, const Vec<ZZ_p>& a, const Vec<ZZ_p>& b)
{
  long n = a.length();
  if (b.length() != n) Error("Vector add: dimension mismatch");

  x.SetLength(n);
  long i;

  for (i = 0; i < n; i ++)
    add(x[i], a[i], b[i]);
}

void InnerProduct(ZZ_p& x, const Vec<ZZ_p>& a, const Vec<ZZ_p>& b)
{
  long n = min(a.length(), b.length());
  long i ;

  ZZ accum, t;

  accum = 0;
  for (i = 0; i < n; i ++ ) {
    mul(t, rep(a[i]), rep(b[i]));
    add(accum, accum, t);
  }

  conv(x, accum);
}

int main()
{
  // initialize modulo p
  long p = 29;
  ZZ_p::init(ZZ(p));

  // declare vector/scalor on ZZ_p
  Vec<ZZ_p> a, b, x;
  ZZ_p prod;

  // vector length
  long n;
  cout << "[*] Input vector Length N: ";
  cin >> n;

  a.SetLength(n);
  b.SetLength(n);

  for (int i = 0; i < n; i ++) {
    conv(a[i], random_ZZ_p());
    conv(b[i], random_ZZ_p());
  }

  cout << "[*] Vector Initialized.\n";
  cout << "a: " << a << "\n";
  cout << "b: " << b << "\n";

  add(x, a, b);
  InnerProduct(prod, a, b);

  cout << "[*] Compute sum/inner product of a, b on Mod " << p << "\n";
  cout << "a + b = " << x << "\n";
  cout << "<a, b> = " << prod << "\n";

}
