include_guard(GLOBAL)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# This bootstrap library contains the existing driver/tool descriptor code.
# It does not include Cell runtime definitions or claim an end-to-end compiler.
add_library(libTexo STATIC
    src/compiler/driver/downstream_compiler_invocation.cc
    src/compiler/tooling/texod_architecture.cc)
add_library(Texo::HostTools ALIAS libTexo)
set_target_properties(libTexo PROPERTIES OUTPUT_NAME Texo EXPORT_NAME HostTools)
target_include_directories(libTexo PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_compile_features(libTexo PUBLIC cxx_std_20)

file(GLOB texo_frontend_sources CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/compiler/frontend/source/*.cc"
    "${PROJECT_SOURCE_DIR}/src/compiler/frontend/parser/*.cc")
add_library(texo_frontend STATIC ${texo_frontend_sources})
add_library(Texo::Frontend ALIAS texo_frontend)
set_target_properties(texo_frontend PROPERTIES EXPORT_NAME Frontend)
target_include_directories(texo_frontend PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_compile_features(texo_frontend PUBLIC cxx_std_20)

add_executable(texo tools/texo/driver_passthrough.cc)
add_executable(Texo::Compiler ALIAS texo)
set_target_properties(texo PROPERTIES EXPORT_NAME Compiler)
target_link_libraries(texo PRIVATE Texo::HostTools)
add_executable(texod tools/texod/texod_architecture.cc)
target_link_libraries(texod PRIVATE Texo::HostTools)

install(TARGETS libTexo texo_frontend texo texod EXPORT TexoTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/Texo"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
set(TEXO_RESOURCE_INSTALL_DIR "${CMAKE_INSTALL_DATADIR}/texo/2.2")
install(DIRECTORY "${PROJECT_SOURCE_DIR}/stdlib/"
    DESTINATION "${TEXO_RESOURCE_INSTALL_DIR}/stdlib")
install(DIRECTORY "${PROJECT_SOURCE_DIR}/profiles/"
    DESTINATION "${TEXO_RESOURCE_INSTALL_DIR}/profiles")
install(EXPORT TexoTargets NAMESPACE Texo::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Texo)
configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/package/TexoConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/TexoConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Texo
    PATH_VARS TEXO_RESOURCE_INSTALL_DIR)
write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/TexoConfigVersion.cmake"
    VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion)
install(FILES "${PROJECT_BINARY_DIR}/TexoConfig.cmake"
    "${PROJECT_BINARY_DIR}/TexoConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Texo)
