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
#include <boost/math/constants/constants.hpp>
#include <boost/math/quadrature/tanh_sinh.hpp>

template<class T>
class func {
public:
  typedef T real_t;
  func(real_t a) : a_(a) {}
  real_t operator()(real_t x) const {
    using std::abs; using std::cos; using std::log;
    auto s = abs(a_ * a_ - 2 * a_ * cos(x) + 1);
    return (s > 0) ? log(s) : real_t(0);
  }
  real_t result() const {
    using std::abs; using std::log;
    using boost::math::constants::pi;
    return (abs(a_) < 1) ? real_t(0) : (2 * pi<real_t>() * log(abs(a_)));
  }
private:
  real_t a_;
};

int main() {
  using std::abs; using std::sqrt;
  typedef double real_t;
  const real_t pi = boost::math::constants::pi<real_t>();

  boost::math::quadrature::tanh_sinh<real_t> integrator;
  real_t termination = sqrt(std::numeric_limits<real_t>::epsilon());
  real_t error, L1;
  size_t levels;
  
  real_t values[5] = { 0.5, 1 - 1e-6, 1, 1 + 1e-6, 1.5 };
  for (auto a : values) {
    func<real_t> f(a);
    real_t q = integrator.integrate(f, 0, pi, termination, &error, &L1, &levels);

    std::cout << std::scientific << std::setprecision(std::numeric_limits<real_t>::digits10)
              << "value of a: " << a << std::endl
              << "result: " << q << std::endl
              << "estimated error: " << error << std::endl
              << "real error: " << abs(q - f.result()) << std::endl
              << "L1 * error: " << L1 * error << std::endl
              << "levels: " << levels << std::endl;
  }
}
