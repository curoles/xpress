/**@file
 * @brief     XPRESS compressor `main` entry.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 */
#include <cstdlib>

#include "Options.h"
#include "lib/ZCompress.h"

#include "filter/FlipInsn.h"

int main(int argc, char* argv[])
{
    // Command line options
    Options options;

    // Parse command line options
    if (!options.parse(argc, argv)) {
        return EXIT_FAILURE;
    }

    ZCompress z;
    bool ok = z.compressFile(options.inputFileName,
        options.outputFileName, FlipInsn::forward);

    if (!ok) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}