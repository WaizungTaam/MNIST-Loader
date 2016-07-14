/*
Copyright 2016 WaizungTaam.  All rights reserved.

License:       Apache License 2.0
Email:         waizungtaam@gmail.com
Creation time: 2016-07-14
Last modified: 2016-07-14
Reference:     http://yann.lecun.com/exdb/mnist/

*/

#include <vector>
#include <iostream>
#include "../src/mnist.h"

int main() {
  MNIST::MNIST_Loader mnist_loader;
  std::vector<std::vector<double>> img_train, img_test;
  std::vector<double> lbl_train, lbl_test;
  mnist_loader.load_train(img_train, lbl_train);
  mnist_loader.load_test(img_test, lbl_test);
  int idx_row, idx_col;
  for (idx_row = 0; idx_row < 28; ++idx_row) {
    for (idx_col = 0; idx_col < 28; ++idx_col) {
      std::cout << img_train[0][idx_row * 28 + idx_col] << "\t";
    }
    std::cout << std::endl;
  }
  std::cout << lbl_train[0] << std::endl << std::endl;
  for (idx_row = 0; idx_row < 28; ++idx_row) {
    for (idx_col = 0; idx_col < 28; ++idx_col) {
      std::cout << img_test[0][idx_row * 28 + idx_col] << "\t";
    }
    std::cout << std::endl;
  }
  std::cout << lbl_test[0] << std::endl;
  return 0;
}
