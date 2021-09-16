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
    static bool forward(void*, uint8_t* buf, unsigned int size);
};