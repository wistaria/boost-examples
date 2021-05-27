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
  func(real_t t) : t_(t) {}
  real_t operator()(real_t x, real_t xc) const {
    using std::abs; using std::cos; using std::log;
    if (x < t_ && xc > 0) {
      return cos(2 * x) * log(abs(2 * sin(xc / 2) * sin((t_ + x) / 2)));
    } else if (x > t_ && xc < 0) {
      return cos(2 * x) * log(abs(2 * sin(-xc / 2) * sin((t_ + x) / 2)));
    } else {
      real_t s = abs(cos(x) - cos(t_));
      return s > 0 ? cos(2 * x) * log(s) : real_t(0);
    }
  }
  real_t result() const {
    using std::cos;
    return -boost::math::constants::pi<real_t>() * cos(2 * t_) / 2;
  }
private:
  real_t t_;
};

int main() {
  using std::abs; using std::sqrt;
  typedef double real_t;
  const real_t pi = boost::math::constants::pi<real_t>();

  boost::math::quadrature::tanh_sinh<real_t> integrator;
  real_t termination = sqrt(std::numeric_limits<real_t>::epsilon());
  
  real_t t = pi / 8;
  func<real_t> f(t);
  real_t error, L1;
  size_t levels;
  real_t q1 = integrator.integrate(f, 0, t, termination, &error, &L1, &levels);
  std::cout << std::scientific << std::setprecision(std::numeric_limits<real_t>::digits10)
            << "lower part: " << q1 << std::endl
            << "estimated error: " << error << std::endl
            << "L1 * error: " << L1 * error << std::endl
            << "levels: " << levels << std::endl;
  real_t q2 = integrator.integrate(f, t, pi, termination, &error, &L1, &levels);
  std::cout << "upper part: " << q2 << std::endl
            << "estimated error: " << error << std::endl
            << "L1 * error: " << L1 * error << std::endl
            << "levels: " << levels << std::endl;
  std::cout << "result: " << (q1 + q2) << std::endl
            << "real error: " << abs(q1 + q2 - f.result()) << std::endl;
}
