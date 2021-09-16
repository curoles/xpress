/**@file
 * @brief     Flip instructions so opcode_bit[n] from different instructions make a byte.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 */
#include "FlipInsn.h"

#include <cstring>

static inline
void set_bit(unsigned char& val, unsigned int pos, unsigned char bit) {
    val |= (bit << pos);
}

static inline
unsigned char get_bit(unsigned char val, unsigned int pos) {
    return (val >> pos) & 1;
}

bool FlipInsn::forward(void*, uint8_t* buf, unsigned int size)
{
    unsigned char tmp[32];

    unsigned int vsize = size / 32;
    for (unsigned int i = 0; i < vsize; ++i) {

        std::memset(tmp, 0, sizeof(tmp));

        for (unsigned int k = 0; k < 4; ++k) {
            for (unsigned int j = 0; j < 8; ++j) {
                for (unsigned int bit_pos = 0; bit_pos < 8; ++bit_pos) {
                    set_bit(tmp[k*8 + j], bit_pos, get_bit(buf[bit_pos*4 + k], j));
                }
            }
        }

        std::memcpy(&buf[i*32], tmp, sizeof(tmp));
    }

    return true;
}
