# 二重指数関数型積分公式 (Double Exponental Formula)
### boost/math/quadrature/tanh_sinh.hpp の利用例

渡辺「二重指数関数型数値積分公式について」核融合研究, **63**, 397 (1990)の例を実行してみる。全ての例で期待した結果が出ている

* 例1 (p.401)
  * `example1.cpp`
  * `example1_fp50.cpp`:  多倍長浮動小数点数(`boost::multiprecision:: cpp_dec_float_50`)を使って積分
  * `example1_fp100.cpp`:  多倍長浮動小数点数(`boost::multiprecision:: cpp_dec_float_100`)を使って積分

* 例2 (p.403)
  * `example2.cpp`
  * `example2_nodiv`: 積分区間を x=θ で分けない場合
  * 注: 表に掲載されているのは θ=π/12 ではなく、θ=π/8 の場合の計算結果であるようなので、この例でも θ=π/8 で計算

* 例3 (p.404)
  * `example3.cpp`
  * `example3_noxc.cpp`: 積分範囲の端における (1-x) の丸め誤差を考慮しない場合

* 例4 (p.405)
  * `example3.cpp`
  * 注: 表に掲載されているのは [0,1] ではなく、[-1,1]の積分結果であるようなので、この例でも [-1,1] で計算

* 例5 (p.405)
  * `example5.cpp`

* 例6 (p.406)
  * `example6.cpp`
