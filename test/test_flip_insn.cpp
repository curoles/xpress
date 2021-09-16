#include <cstdlib>
#include <cstdio>
#include <cstring>
#undef NDEBUG
#include <cassert>

#include "filter/FlipInsn.h"

void print_binary(uint8_t b, FILE* f = stdout) {
    fprintf(f, "%u%u%u%u%u%u%u%u",
        (b >> 7)&1, (b >> 6)&1, (b >> 5)&1,(b >> 4)&1,
        (b >> 3)&1, (b >> 2)&1, (b >> 1)&1, (b >> 0)&1);
}

static bool test1()
{
    uint8_t data[FlipInsn::GROUP_SIZE] = {
        1, 2, 4, 8, 16, 32, 64, 128,
        1, 2, 4, 8, 16, 32, 64, 128,
        1, 2, 4, 8, 16, 32, 64, 128,
        1, 2, 4, 8, 16, 32, 64, 128
    };

    uint8_t original_data[FlipInsn::GROUP_SIZE];
    memcpy(original_data, data, sizeof(data));

    for (unsigned int i = 0; i < 8; ++i) {
        print_binary(data[i*4 + 3]); putchar(' ');
        print_binary(data[i*4 + 2]); putchar(' ');
        print_binary(data[i*4 + 1]); putchar(' ');
        print_binary(data[i*4 + 0]); putchar('\n');
    }

    FlipInsn::forward(nullptr, data, sizeof(data));

    putchar('\n');

    for (unsigned int i = 0; i < 8; ++i) {
        print_binary(data[i*4 + 3]); putchar(' ');
        print_binary(data[i*4 + 2]); putchar(' ');
        print_binary(data[i*4 + 1]); putchar(' ');
        print_binary(data[i*4 + 0]); putchar('\n');
    }

    FlipInsn::backward(nullptr, data, sizeof(data));

    putchar('\n');

    for (unsigned int i = 0; i < 8; ++i) {
        print_binary(data[i*4 + 3]); putchar(' ');
        print_binary(data[i*4 + 2]); putchar(' ');
        print_binary(data[i*4 + 1]); putchar(' ');
        print_binary(data[i*4 + 0]); putchar('\n');
    }

    int cmp_res = memcmp(original_data, data, sizeof(data));

    assert(cmp_res == 0);

    return true;
}

static bool test2()
{
    uint8_t data[FlipInsn::GROUP_SIZE * 2] = {
        0xf9, 0xef, 0x48, 0xab, 0x33, 0x16, 0x06, 0x05,
        0xff, 2, 4, 8, 16, 32, 64, 128,
        1, 2, 4, 0x12, 16, 32, 64, 128,
        0xbc, 0xff, 0x00, 0x8a, 0x9b, 0x77, 0x88, 0x9d,
        0xf9, 0xef, 0x48, 0xab, 0x33, 0x16, 0x06, 0x05,
        0xff, 2, 4, 8, 16, 32, 64, 128,
        1, 2, 4, 0x12, 16, 32, 64, 128,
        0xbc, 0xff, 0x00, 0x8a, 0x9b, 0x77, 0x88, 0x9d
    };

    uint8_t original_data[FlipInsn::GROUP_SIZE * 2];
    memcpy(original_data, data, sizeof(data));

    putchar('\n');

    for (unsigned int n = 1; n < 2; ++n)
    for (unsigned int i = 0; i < 8; ++i) {
        print_binary(data[n*32 + i*4 + 3]); putchar(' ');
        print_binary(data[n*32 + i*4 + 2]); putchar(' ');
        print_binary(data[n*32 + i*4 + 1]); putchar(' ');
        print_binary(data[n*32 + i*4 + 0]); putchar('\n');
    }

    FlipInsn::forward(nullptr, data, sizeof(data));

    putchar('\n');

    for (unsigned int n = 1; n < 2; ++n)
    for (unsigned int i = 0; i < 8; ++i) {
        print_binary(data[n*32 + i*4 + 3]); putchar(' ');
        print_binary(data[n*32 + i*4 + 2]); putchar(' ');
        print_binary(data[n*32 + i*4 + 1]); putchar(' ');
        print_binary(data[n*32 + i*4 + 0]); putchar('\n');
    }

    FlipInsn::backward(nullptr, data, sizeof(data));

    putchar('\n');

    for (unsigned int n = 1; n < 2; ++n)
    for (unsigned int i = 0; i < 8; ++i) {
        print_binary(data[n*32 + i*4 + 3]); putchar(' ');
        print_binary(data[n*32 + i*4 + 2]); putchar(' ');
        print_binary(data[n*32 + i*4 + 1]); putchar(' ');
        print_binary(data[n*32 + i*4 + 0]); putchar('\n');
    }

    int cmp_res = memcmp(original_data, data, sizeof(data));

    assert(cmp_res == 0);

    return true;
}

int main(void)
{
    assert(test1());
    assert(test2());

    return EXIT_SUCCESS;
}