/**@file
 * @brief     XPRESS command line options.
 * @author    Igor Lesik 2021
 * @copyright Tachyum Ltd. 2021
 */
#pragma once

#include <string>
#include <vector>
#include <cstdint>

/// XPRESS command line options.
///
struct Options
{
    bool verbose{false}; ///< show details about compression process

    std::string inputFileName; ///< executable file to compress
    std::string outputFileName; ///< compressed output file

    bool isLoggingEnabled{false};
    std::string logFileName{"xpress.log"};


public:
    /// Parse XPRESS command line options.
    bool parse(int argc, char** argv);
};
