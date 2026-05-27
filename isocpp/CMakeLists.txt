cmake_minimum_required(VERSION 3.16)

project(isocpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(isocpp main.cpp
    NR5.cpp
    NR2.cpp
    CP1.cpp)

include(GNUInstallDirs)
install(TARGETS isocpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
