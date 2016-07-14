/*
Copyright 2016 WaizungTaam.  All rights reserved.

License:       Apache License 2.0
Email:         waizungtaam@gmail.com
Creation time: 2016-07-14
Last modified: 2016-07-14
Reference:     http://yann.lecun.com/exdb/mnist/

*/

#ifndef MNIST_H
#define MNIST_H

#include <vector>
#include <fstream>
#include <string>

namespace MNIST {

const int IMG_MAGIC_NUMBER = 2051;
const int LBL_MAGIC_NUMBER = 2049;
const std::string FILE_IMG_TRAIN = "train-images.idx3-ubyte";
const std::string FILE_LBL_TRAIN = "train-labels.idx1-ubyte";
const std::string FILE_IMG_TEST = "t10k-images.idx3-ubyte";
const std::string FILE_LBL_TEST = "t10k-labels.idx1-ubyte";

class MNIST_Loader {
public:
  MNIST_Loader() = default;
  MNIST_Loader(std::string);
  MNIST_Loader(const MNIST_Loader &) = default;
  MNIST_Loader(MNIST_Loader &&) = default;
  MNIST_Loader & operator=(const MNIST_Loader &) = default;
  MNIST_Loader & operator=(MNIST_Loader &&) = default;
  ~MNIST_Loader() = default;
  void load_train(std::vector<std::vector<double>> &, std::vector<double> &);
  void load_test(std::vector<std::vector<double>> &, std::vector<double> &);
private:
  std::string path;
  struct ImgHeader {
    unsigned char magic_number[4];
    unsigned char num_imgs[4];
    unsigned char num_rows[4];
    unsigned char num_cols[4];
  };
  struct LblHeader {
    unsigned char magic_number[4];
    unsigned char num_lbls[4];
  };  
  int uchar_to_int(unsigned char *, std::size_t);
  void read_img_header(std::ifstream &, ImgHeader &);
  void read_lbl_header(std::ifstream &, LblHeader &);
  void load_img(std::ifstream &, std::vector<std::vector<double>> &);
  void load_lbl(std::ifstream &, std::vector<double> &);
};

}  // namespace MNIST

#endif  // mnist.h