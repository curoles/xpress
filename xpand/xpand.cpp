/**@file
 * @brief     XPAND decompressor `main` entry.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 */
#include <cstdlib>

#include "Options.h"
#include "lib/ZCompress.h"

int main(int argc, char* argv[])
{
    // Command line options
    Options options;

    // Parse command line options
    if (!options.parse(argc, argv)) {
        return EXIT_FAILURE;
    }

    ZCompress z;
    if (!z.decompressFile(options.inputFileName, options.outputFileName)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}