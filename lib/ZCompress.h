/**@file
 * @brief     ZLIB wrapper.
 * @author    Igor Lesik 2021
 * @copyright Tachyum Ltd. 2021
 */
#pragma once

#include <cstdio>
#include <string>
#include "zlib.h"

class ZCompress
{
public:
    static const unsigned int CHUNK_SIZE = 2*1024*1024;
public:
    static int zdeflate(FILE *source, FILE *dest, int level = Z_DEFAULT_COMPRESSION);
    static int zinflate(FILE *source, FILE *dest);
    static void reportZErr(int ret);

    static bool compressFile(const std::string& inFileName, const std::string& outFileName);
    static bool decompressFile(const std::string& inFileName, const std::string& outFileName);
};