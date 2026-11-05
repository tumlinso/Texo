include(GNUInstallDirs)
configure_file("${CMAKE_CURRENT_LIST_DIR}/texo.pc.in" "${CMAKE_CURRENT_BINARY_DIR}/texo.pc" @ONLY)
set(TEXO_PKGCONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/pkgconfig")
