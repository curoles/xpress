/**@file
 * @brief     Flip instructions so opcode_bit[n] from different instructions make a byte.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 */
#pragma once

#include <cstdint>

class FlipInsn
{
public:
    static const uint8_t INSN_SIZE = 4;
    static const uint8_t NR_BITS_IN_BYTE = 8;
    static const uint8_t NR_INSN_IN_GROUP = NR_BITS_IN_BYTE;
    static const uint8_t GROUP_SIZE = NR_INSN_IN_GROUP * INSN_SIZE;
public:
    static bool forward(void*, uint8_t* buf, unsigned int size);
    static bool backward(void*, uint8_t* buf, unsigned int size);
};