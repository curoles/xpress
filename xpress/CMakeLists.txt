set(XPRESS_SRC_FILES
    xpress.cpp
    Options.cpp
    ${XPRESS_SOURCE_DIR}/lib/ZCompress.cpp
)

add_executable(xpress ${XPRESS_SRC_FILES})

#add_dependencies(xpress zlib)

target_compile_options(xpress
    PUBLIC -fpie -Wl,-pie
)

#target_link_options(xpress PUBLIC -Wl,--disable-new-dtags,-rpath,${TACHY_TOOLCHAIN_HOME}/lib/)

#target_include_directories(psim-fun PUBLIC
#    ${PSIM_SOURCE_DIR}/sim/exec # for FSIM's exec-fns.h to see sim/exec/xec-inputs.h
#)

#link_directories(${TACHY_TOOLCHAIN_HOME}/???)

add_library(xpress_interface_libs INTERFACE)
target_link_libraries(xpress_interface_libs
    INTERFACE -lz
    #INTERFACE ${SYSTEMC_LIB_DIR}/libsystemc.so
    #INTERFACE ${TACHY_TOOLCHAIN_HOME}/lib/libcofsim.so
    #INTERFACE ${TACHY_TOOLCHAIN_HOME}/lib/libbfd-2.36.50.20210422.so
    #INTERFACE -pthread # for gdb-sim
    #INTERFACE -lsqlite3
)

target_link_libraries(xpress
    PUBLIC xpress_interface_libs
)

set_target_properties(xpress PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)

install(TARGETS xpress
    CONFIGURATIONS Debug
    RUNTIME DESTINATION debug/bin
)

install(TARGETS xpress
    CONFIGURATIONS Release
    RUNTIME DESTINATION release/bin
)