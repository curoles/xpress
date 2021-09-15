include(ExternalProject)

ExternalProject_Add(zlib
    PREFIX zlib_dir
    GIT_REPOSITORY https://github.com/madler/zlib
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/zlib_dir -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
    BUILD_COMMAND make -j
    UPDATE_COMMAND ""
)
