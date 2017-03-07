// Copyright (c) 2015-2016, ETH Zurich, Wyss Zurich, Zurich Eye
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the ETH Zurich, Wyss Zurich, Zurich Eye nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL ETH Zurich, Wyss Zurich, Zurich Eye BE LIABLE
// FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <plotty/matplotlibcpp.hpp>

int main() {
  // Simple:
  std::vector<double> v({1, 2, 3, 4});
  plotty::plot(v);
  plotty::show();

  // Eigen Vector Types:
  Eigen::VectorXd times(100);
  times.setLinSpaced(100, 0, 20);
  Eigen::VectorXd points(100);
  points.setRandom();

  plotty::plot(times, points);
  plotty::show();

  plotty::labelPlot("A Name", times, points);
  plotty::show();

  // enable interactive mode as of now (only tests if it doesn't crash)
  plotty::ion();

  // subplots
  plotty::subplot(3, 1, 1);
  plotty::plot(v);
  plotty::subplot(3, 1, 2);
  plotty::plot(v);
  plotty::subplot(3, 1, 3);
  plotty::plot(v);
  plotty::show(false);

  plotty::figure();

  // plot multiple curves in a single graph
  std::vector<double> w({4, 3, 2, 1});
  plotty::plot(v, "x");
  plotty::plot(w, "o");
  plotty::show();

  // Histogram
  plotty::hist(points, 3);
  plotty::show();

  // Row vectors
  Eigen::MatrixXd matrix(2, 100);
  matrix.setRandom();
  plotty::plot(matrix.row(0), matrix.row(1));
  plotty::show();

  // BoxPlot
  Eigen::MatrixXd data(2, 100);
  data.setRandom();
  plotty::figure();
  std::vector<std::string> labels = {"A", "B"};
  plotty::boxplot(data, labels);
  plotty::show();

  // BoxPlot
  data.setRandom();
  plotty::figure();
  plotty::boxplot(data, {"A", "B"});
  plotty::show();

  // Boxplot unlabelled
  data.setRandom();
  plotty::figure();
  plotty::boxplot(data);
  plotty::show();
}
