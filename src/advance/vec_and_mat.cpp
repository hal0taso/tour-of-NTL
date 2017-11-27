#include <NTL/matrix.h>
#include <NTL/vector.h>
#include <NTL/ZZ_p.h>

using namespace std;
using namespace NTL;

void InnerProduct(ZZ_p& x, const Vec<ZZ_p>& a, const Vec<ZZ_p>& b)
{
  long n = min(a.length(), b.length());
  long i ;

  ZZ_p accum;

  for (i = 0; i < n; i ++ ) {
    accum += a[i] * b[i];
  }

  conv(x, accum);
}

void mul(Vec<ZZ_p>& x, const Mat<ZZ_p>& B, const Vec<ZZ_p>& z)
{
  long n, m;
  long i;
  n = B.NumCols();
  m = B.NumRows();

  x.SetLength(n);

  ZZ_p accum;

  if (n != z.length()) Error("[*] mul: dimention mismatch");

  for(i = 0; i < m; ++i) {
    InnerProduct(accum, B[i], z);
    conv(x[i], accum);
  }
}

int main()
{
  // Define Matrix B, Vector x,z
  Mat<ZZ_p> B;
  Vec<ZZ_p> x, z;

  // Define module parameter p
  long p;

  // Define Matrix parameter n,m
  long n, m;

  long i,j;


  // Set module parameter p
  cout << "[Module] p: ";
  cin >> p;

  if (p < 2) Error("Input Error: p must greater than 1");

  ZZ_p::init(ZZ(p));


  // Set Matrix Row n, Column m
  cout << "[Row] m: ";
  cin >> m;
  cout << "[Column] n: ";
  cin >> n;

  if (n == 0 || m == 0) Error("Input Error: n, m must nonzero Integer.");

  B.SetDims(m, n);
  z.SetLength(n);

  // Generate random m x n Matrix
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      conv(B[i][j], random_ZZ_p());
    }
  }

  cout << "B: \n" << B << "\n";
  // Generate random n dimensional vector z
  for (i = 0; i < n; ++i) {
    conv(z[i], random_ZZ_p());
  }

  cout << "z: \n" << z << "\n";

  mul(x, B, z);

  cout << "Bz: \n" << x;

}
