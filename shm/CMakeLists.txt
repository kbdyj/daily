cmake_minimum_required(VERSION 3.16)

project(shm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shm main.cpp
    test_consumer_producer.cpp
    test_shm.cpp
    test_pipe.cpp
    test_fork.cpp

)

include(GNUInstallDirs)
install(TARGETS shm
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
