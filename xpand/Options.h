/**@file
 * @brief     XPAND command line options.
 * @author    Igor Lesik 2021
 * @copyright Tachyum Ltd. 2021
 */
#pragma once

#include <string>
#include <vector>
#include <cstdint>

/// XPAND command line options.
///
struct Options
{
    bool verbose{false}; ///< show details about compression process

    std::string inputFileName; ///< input file to decompress
    std::string outputFileName; ///< decompressed output file

    bool isLoggingEnabled{false};
    std::string logFileName{"xpand.log"};


public:
    /// Parse XPAND command line options.
    bool parse(int argc, char** argv);
};
