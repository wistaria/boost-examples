/*****************************************************************************
*
* Copyright (C) 2021 by Synge Todo <wistaria@phys.s.u-tokyo.ac.jp>
*
* Distributed under the Boost Software License, Version 1.0. (See accompanying
* file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*****************************************************************************/

#include <iomanip>
#include <iostream>
#include <cmath>
#include <limits>
#include <boost/math/quadrature/exp_sinh.hpp>
#include <boost/math/special_functions/gamma.hpp>
#include <boost/math/special_functions/zeta.hpp>

template<class T>
class func {
public:
  typedef T real_t;
  func(real_t s) : s_(s) {}
  real_t operator()(real_t x) const {
    using std::exp; using std::pow; using std::sqrt;
    if ((exp(x) - 1) > sqrt(std::numeric_limits<real_t>::epsilon())) {
      return pow(x, s_ - 1) / (exp(x) - 1);
    } else {
      return pow(x, s_ - 1) / (x + x * x / 2);
    }
  }
  real_t result() const {
    return boost::math::tgamma(s_) * boost::math::zeta(s_);
  }
private:
  real_t s_;
};

int main() {
  using std::abs; 
  typedef double real_t;
  
  boost::math::quadrature::exp_sinh<real_t> integrator;
  real_t termination = sqrt(std::numeric_limits<real_t>::epsilon());
  real_t error, L1;
  size_t levels;

  real_t values[5] = { 1.1, 1.5, 2, 2.5, 3 };
  for (auto s : values) {
    func<real_t> f(s);
    real_t q = integrator.integrate(f, termination, &error, &L1, &levels);

    std::cout << std::scientific << std::setprecision(std::numeric_limits<real_t>::digits10)
              << "value of s: " << s << std::endl
              << "result: " << q << std::endl
              << "estimated error: " << error << std::endl
              << "real error: " << abs(q - f.result()) << std::endl
              << "L1 * error: " << L1 * error << std::endl
              << "levels: " << levels << std::endl;
  }
}
