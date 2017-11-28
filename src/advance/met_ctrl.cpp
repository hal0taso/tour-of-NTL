#include <NTL/mat_ZZ_p.h>
#include <NTL/vec_ZZ_p.h>
#include <NTL/ZZ_p.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

// change A[][i] to x
void exchcols(Mat<ZZ_p>& X, Mat<ZZ_p>& A, Vec<ZZ_p>& x, const long i)
{
  long n = A.NumCols();
  long m = A.NumRows();
  long j;

  // Error handling
  if (m != x.length()) Error("chcols: dimension mismatch");
  if (n < i) Error("chcols: query i is out of range");

  X.SetDims(n, m);
  conv(X, A);

  // exchange column vector
  for (j = 0; j < m; ++j){
    X[j].put(i, x[j]);
  }
}

int main()
{
  long n;
  long i;

  Mat<ZZ_p> A,B;
  Vec<ZZ_p> x;

  ZZ p;

  cout << "n: ";
  cin >> n;

  RandomPrime(p, 4);
  ZZ_p::init(p);
  cout << "p: " << p << "\n";

  random(A, n, n);
  cout << "A: \n" << A << "\n";

  random(x, n);
  cout << "x: " << x << "\n";

  cout << "Ax = " << A*x << "\n";

  cout << "Exchange Column of A with x\n";
  cout << "Input Column Index: ";
  cin >> i;

  exchcols(B, A, x, i);

  cout << B << "\n";
}
