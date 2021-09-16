/**@file
 * @brief     XPAND command line options.
 * @author    Igor Lesik 2021
 * @copyright Tachyum Ltd. 2021
 */
#include "Options.h"

// https://github.com/CLIUtils/CLI11
#include "lib/CLI11.hpp"

/// Parse XPAND's command line options.
///
bool Options::parse(int argc, char** argv)
{
    CLI::App app{"XPAND executable file decompressor"};

    this->inputFileName = "NO INPUT FILE PROVIDED";

    app.add_flag("-v,--verbose", this->verbose, "verbose output");

    app.add_option("-l,--log", this->logFileName, "log file")->
        each([this](const std::string &){this->isLoggingEnabled = true;});


    // Positional option, compressed input file
    app.add_option("input_file_name", this->inputFileName, "path to compressed input file")
        ->required()
        ->check(CLI::ExistingFile);

    // Positional option, output compressed file
    app.add_option("output_file_name", this->outputFileName, "path to output decompressed file")
        ->required();

    try
    {
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e)
    {
        app.exit(e);
        return false;
    }

    return true;
}
