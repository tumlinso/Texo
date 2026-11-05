cmake_minimum_required(VERSION 3.28)
project(Texo VERSION 0.1.0 LANGUAGES C CXX)

include(GNUInstallDirs)
include(CTest)
option(TEXO_BUILD_TESTS "Build the extracted host compiler contract tests" ON)

include(cmake/compiler/TexoHostSdk.cmake)

if(TEXO_BUILD_TESTS)
    include(cmake/TexoHostTests.cmake)
endif()
