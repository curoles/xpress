add_executable(test_flip_insn
    ${CMAKE_CURRENT_SOURCE_DIR}/test_flip_insn.cpp
    ${CMAKE_SOURCE_DIR}/filter/FlipInsn.cpp
)
#add_dependencies(test_flip_insn zlib)

add_test(NAME test-flip-insn
    COMMAND test_flip_insn
)
