cmake_minimum_required(VERSION 3.14)

project(Product_Program LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Product_Program
  main.cpp
  product.h
  product.cpp
  foodproduct.h
  foodproduct.cpp
  transaction.h
  transaction.cpp

)
target_link_libraries(Product_Program Qt${QT_VERSION_MAJOR}::Core)
