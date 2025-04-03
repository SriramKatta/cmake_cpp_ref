#ifndef HEADER_HPP
#define HEADER_HPP
#pragma once  // Redundant but Safe

#include <Eigen/Dense>

namespace test {
  Eigen::MatrixXd superfunc() {
    return Eigen::MatrixXd::Ones(3, 3);
  }
}  // namespace test

#endif