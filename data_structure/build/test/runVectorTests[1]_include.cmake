if(EXISTS "/media/ljy/data/cpplearning/cpp_basic_learning/data_structure/build/test/runVectorTests[1]_tests.cmake")
  include("/media/ljy/data/cpplearning/cpp_basic_learning/data_structure/build/test/runVectorTests[1]_tests.cmake")
else()
  add_test(runVectorTests_NOT_BUILT runVectorTests_NOT_BUILT)
endif()