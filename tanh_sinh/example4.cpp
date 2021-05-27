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

int main() {
  using std::abs; using std::sqrt;
  typedef double real_t;

  auto f = [](real_t x) { return sqrt(1 - x * x); };
  real_t r = boost::math::constants::pi<real_t>() / 2;
  
  boost::math::quadrature::tanh_sinh<real_t> integrator;
  real_t termination = sqrt(std::numeric_limits<real_t>::epsilon());
  real_t error, L1;
  size_t levels;
  real_t q = integrator.integrate(f, -1, 1, termination, &error, &L1, &levels);

  std::cout << std::scientific << std::setprecision(std::numeric_limits<real_t>::digits10)
            << "result: " << q << std::endl
            << "estimated error: " << error << std::endl
            << "real error: " << abs(q - r) << std::endl
            << "L1 * error: " << L1 * error << std::endl
            << "levels: " << levels << std::endl;
}
