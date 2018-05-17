# test_hw1
software testing homework1

[![Build Status](https://travis-ci.org/kamineko2016/test_hw1.svg?branch=master)](https://travis-ci.org/kamineko2016/test_hw1)
[![codecov](https://codecov.io/gh/kamineko2016/test_hw1/branch/master/graph/badge.svg)](https://codecov.io/gh/kamineko2016/test_hw1)

編譯方式:

在 clone 後的主目錄下
先用 git submodule update --init --recursive 載入 google test
再用 make 指令編譯即可

執行編譯後的檔案指令

./hw1_Triangle_test

./hw1_NextDate_test

./hw1_Commission_test

GCOV指令

gcov -a hw1_Triangle.cc

gcov -a hw1_NextDate.cc

gcov -a hw1_Commission.cc

gcov -b hw1_Triangle.cc

gcov -b hw1_NextDate.cc

gcov -b hw1_Commission.cc


