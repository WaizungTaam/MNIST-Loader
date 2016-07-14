MNIST Loader
============

Introduction
------------
This is a C++11 MNIST database loader.

Usages
------
- MNIST::MNIST_Loader: Create a MNIST data loader that loads files from current directory.
- MNIST::MNIST_Loader(path): Create a MNIST data loader that loads files from a specified path.
- load_train: Load the training images and labels.
- load_test: Load the testing images and labels.

The image data is stored by a two-dimensional std::vector of type double,
and the label data is stored by a one-dimensional std::vector of type double.

MNIST
-----
MNIST is a database of handwritten digits.
For further information of MNIST database, please refer to 
[http://yann.lecun.com/exdb/mnist/](http://yann.lecun.com/exdb/mnist/)

Demo
----

- Download data files from [http://yann.lecun.com/exdb/mnist/](http://yann.lecun.com/exdb/mnist/)
- Uncompress the data files and put them in the parent directory of this repository
- `$ make`

Compile test passed on Ubuntu 14.04.3 LTS, g++ 4.8.4.