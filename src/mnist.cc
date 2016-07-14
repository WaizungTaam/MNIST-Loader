/*
Copyright 2016 WaizungTaam.  All rights reserved.

License:       Apache License 2.0
Email:         waizungtaam@gmail.com
Creation time: 2016-07-14
Last modified: 2016-07-14
Reference:     http://yann.lecun.com/exdb/mnist/

*/

#include <vector>
#include <fstream>
#include <string>
#include "mnist.h"

namespace MNIST {

MNIST_Loader::MNIST_Loader(std::string path_init) : path(path_init) {
}
void MNIST_Loader::load_train(std::vector<std::vector<double>> & img_data, 
                              std::vector<double> & lbl_data) {
  std::ifstream ifs_img(path + FILE_IMG_TRAIN, std::ios::binary);
  std::ifstream ifs_lbl(path + FILE_LBL_TRAIN, std::ios::binary);
  if (ifs_img.is_open()) {
    load_img(ifs_img, img_data);
  } else {
    throw "Cannot open " + FILE_IMG_TRAIN;
  }
  if (ifs_lbl.is_open()) {
    load_lbl(ifs_lbl, lbl_data);
  } else {
    throw "Cannot open " + FILE_LBL_TRAIN;
  }
}
void MNIST_Loader::load_test(std::vector<std::vector<double>> & img_data, 
                             std::vector<double> & lbl_data) {
  std::ifstream ifs_img(path + FILE_IMG_TEST, std::ios::binary);
  std::ifstream ifs_lbl(path + FILE_LBL_TEST, std::ios::binary);
  if (ifs_img.is_open()) {
    load_img(ifs_img, img_data);
  } else {
    throw "Cannot open " + path + FILE_IMG_TEST;
  }
  if (ifs_lbl.is_open()) {
    load_lbl(ifs_lbl, lbl_data);
  } else {
    throw "Cannot open " + path + FILE_LBL_TEST;
  }  
}
int MNIST_Loader::uchar_to_int(unsigned char * uchar_arr, std::size_t len) {
  int res = static_cast<int>(uchar_arr[0]);
  std::size_t index;
  for (index = 1; index < len; ++index) {
    res = (res << 8) + uchar_arr[index];
  }
  return res;
}
void MNIST_Loader::read_img_header(std::ifstream & ifs, ImgHeader & img_header) {
  ifs.read((char*)(&(img_header.magic_number)), sizeof(img_header.magic_number));
  ifs.read((char*)(&(img_header.num_imgs)), sizeof(img_header.num_imgs));
  ifs.read((char*)(&(img_header.num_rows)), sizeof(img_header.num_rows));
  ifs.read((char*)(&(img_header.num_cols)), sizeof(img_header.num_cols));
}
void MNIST_Loader::read_lbl_header(std::ifstream & ifs, LblHeader & lbl_header) {
  ifs.read((char*)(&(lbl_header.magic_number)), sizeof(lbl_header.magic_number));
  ifs.read((char*)(&(lbl_header.num_lbls)), sizeof(lbl_header.num_lbls));
}
void MNIST_Loader::load_img(std::ifstream & ifs, 
                            std::vector<std::vector<double>> & img_data) {
  int magic_number, num_imgs, num_rows, num_cols,
      idx_img, idx_row, idx_col, idx_data_row;
  unsigned char tmp_read;
  ImgHeader img_header;
  read_img_header(ifs, img_header);
  magic_number = uchar_to_int(img_header.magic_number, 4);
  if (magic_number != IMG_MAGIC_NUMBER) {
    throw "Invalid MNIST file";
  }
  num_imgs = uchar_to_int(img_header.num_imgs, 4);
  num_rows = uchar_to_int(img_header.num_rows, 4);
  num_cols = uchar_to_int(img_header.num_cols, 4);
  img_data.resize(num_imgs);
  for (idx_img = 0; idx_img < num_imgs; ++idx_img) {
    img_data[idx_img].resize(num_rows * num_cols);
  }
  for (idx_img = 0; idx_img < num_imgs; ++idx_img) {
    for (idx_data_row = 0; idx_data_row < num_rows * num_cols; ++idx_data_row) {
      ifs.read((char*)(&tmp_read), sizeof(tmp_read));
      img_data[idx_img][idx_data_row] = static_cast<double>(tmp_read);
    }
  }
}
void MNIST_Loader::load_lbl(std::ifstream & ifs, 
                            std::vector<double> & lbl_data) {
  int magic_number, num_lbls, idx_lbl;
  unsigned char tmp_read;
  LblHeader lbl_header;
  read_lbl_header(ifs, lbl_header);
  magic_number = uchar_to_int(lbl_header.magic_number, 4);
  if (magic_number != LBL_MAGIC_NUMBER) {
    throw "Invalid MNIST file";
  }
  num_lbls = uchar_to_int(lbl_header.num_lbls, 4);
  lbl_data.resize(num_lbls);
  for (idx_lbl = 0; idx_lbl < num_lbls; ++idx_lbl) {
    ifs.read((char*)(&tmp_read), sizeof(tmp_read));
    lbl_data[idx_lbl] = static_cast<double>(tmp_read);
  }
}

}  // namespace MNIST