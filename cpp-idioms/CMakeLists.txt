cmake_minimum_required(VERSION 3.16)

project(cpp-idioms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp-idioms main.cpp
    checkable_delete.cpp
    deleter.hpp
    deleter.cpp
    object.hpp)

include(GNUInstallDirs)
install(TARGETS cpp-idioms
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
