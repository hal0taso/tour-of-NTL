#include <NTL/ZZ.h>
#include <NTL/matrix.h>

using namespace std;
using namespace NTL;

void mul(Mat<ZZ>& X, const Mat<ZZ>& A, const Mat<ZZ>& B)
{
  long m = A.NumRows();
  long n = A.NumCols();
  long l = B.NumCols();

  if (n != B.NumRows())
    Error("matrix mul: dimensiom mismatch");

  X.SetDims(m, l); // make X have m rows and l columns

  long i, j, k;
  ZZ acc, tmp;

  for (i = 1; i <= m; i ++) {
    for (j = 1; j <= l; j ++) {
      acc = 0;
      for (k = 1; k <= n; k ++) {
        mul(tmp, A(i, k), B(k, j));
        add(acc, acc, tmp);
      }
      X(i, j) = acc;
    }
  }
}

int main()
{
  // long n, m;
  Mat<ZZ> X, A, B;

  // cout << "m: ";
  // cin >> m;
  // cout << "n: ";
  // cin >> n;

  cout << "A: \n";
  cin >> A;
  cout << "B: \n";
  cin >> B;

  mul(X, A, B);

  cout << "AB = \n" << X;



}
