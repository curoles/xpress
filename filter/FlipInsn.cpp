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
    unsigned char tmp[GROUP_SIZE];

    unsigned int nr_groups = size / GROUP_SIZE;
    for (unsigned int group = 0; group < nr_groups; ++group) {

        std::memset(tmp, 0, sizeof(tmp));
        unsigned int buf_offset = group*GROUP_SIZE;

        for (unsigned int k = 0; k < 4; ++k) {
            for (unsigned int j = 0; j < 8; ++j) {
                for (unsigned int bit_pos = 0; bit_pos < 8; ++bit_pos) {
                    set_bit(tmp[k*8 + j], bit_pos, get_bit(buf[buf_offset + bit_pos*4 + k], j));
                }
            }
        }

        std::memcpy(&buf[buf_offset], tmp, sizeof(tmp));
    }

    return true;
}

bool FlipInsn::backward(void*, uint8_t* buf, unsigned int size)
{
    unsigned char tmp[GROUP_SIZE];

    unsigned int nr_groups = size / GROUP_SIZE;
    for (unsigned int group = 0; group < nr_groups; ++group) {

        std::memset(tmp, 0, sizeof(tmp));
        unsigned int buf_offset = group*GROUP_SIZE;

        for (unsigned int k = 0; k < 4; ++k) {
            for (unsigned int j = 0; j < 8; ++j) {
                for (unsigned int bit_pos = 0; bit_pos < 8; ++bit_pos) {
                    //set_bit(tmp[k*8 + j], bit_pos, get_bit(buf[bit_pos*4 + k], j));
                    set_bit(tmp[bit_pos*4 + k], j, get_bit(buf[buf_offset + k*8 + j], bit_pos));
                }
            }
        }

        std::memcpy(&buf[buf_offset], tmp, sizeof(tmp));
    }

    return true;
}
