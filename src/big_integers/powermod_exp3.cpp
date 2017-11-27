#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ PowerMod(ZZ& a, ZZ& e, ZZ&n)
{
  if (e == 0) return ZZ(1);

  long k = NumBits(e);

  ZZ res;
  res = 1;

  for (long i = k - 1; i >= 0; i --){

    // simple Implementation
    //   res = (res * res) % n;
    //   if (bit(e, i) == 1) res = (res * a) % n;

    // we can implement as follows
    // res = SqrMod(res, n);
    // if (bit(e, i) == 1) res = MulMod(res, a, n);

    // we can also write this as
    SqrMod(res, res, n);
    if (bit(e, i) == 1) MulMod(res, res, a, n);

  }


  if ( e < 0)
    return InvMod(res, n);
  else
    return res;
}

int main(){
  ZZ a, e, n;
  ZZ ret;

  cout << "a: ";
  cin >> a;

  cout << "e: ";
  cin >> e;

  cout << "n: ";
  cin >> n;

  ret = PowerMod(a, e, n);

  cout << a << " ^ " << e << " mod " << n << " = " << ret;

}
