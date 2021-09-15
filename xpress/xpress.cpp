/**@file
 * @brief     XPRESS compressor `main` entry.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 */
#include <cstdlib>

#include "Options.h"

int main(int argc, char* argv[])
{
    // Command line options
    Options options;

    // Parse command line options
    if (!options.parse(argc, argv)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}