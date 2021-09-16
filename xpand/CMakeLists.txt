set(XPAND_SRC_FILES
    xpand.cpp
    Options.cpp
    ${XPRESS_SOURCE_DIR}/lib/ZCompress.cpp
)

add_executable(xpand ${XPAND_SRC_FILES})

#add_dependencies(xpand zlib)

target_compile_options(xpand
    PUBLIC -fpie -Wl,-pie
)

add_library(xpand_interface_libs INTERFACE)
target_link_libraries(xpand_interface_libs
    INTERFACE -lz
)

target_link_libraries(xpand
    PUBLIC xpand_interface_libs
)

set_target_properties(xpand PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)

install(TARGETS xpand
    CONFIGURATIONS Debug
    RUNTIME DESTINATION debug/bin
)

install(TARGETS xpand
    CONFIGURATIONS Release
    RUNTIME DESTINATION release/bin
)