# Tour of NTL (advanced)
ドキュメントをみればわかることですがとりあえず試したことを書いていく

## vec_and_mat.cpp
ここではZZ_p上での

- 一様ランダムな行列、ベクトルの生成
- 行列とベクトルの掛け算

を実装してみた。これはすでに[mat_ZZ_p](http://www.shoup.net/ntl/doc/mat_ZZ_p.cpp.html)と[vec_ZZ_p](http://www.shoup.net/ntl/doc/vec_ZZ_p.cpp.html)で実装されている機能である。

## met_ctrl.cpp
ここでは正方行列の指定した列をベクトルで置き換えることを行う。

```
// change A[][i] to x and return new Matrix X
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
```

行`v`をベクトル`x`で置き換えるのは置き換えたいvectorに関して`v.swap(x)`もしくは`v.move(x)`のようにすれば問題なく行える

`swap(Vec& y)`と`move(Vec& y)`の違いは、swapはyとそのベクトルを入れ替えるのに対して、(内部ではポインタの交換が生じている)moveは元のベクトルは破棄される(元のベクトルのポインタが新しいベクトルのポインタに置き換えられる)ことである。
