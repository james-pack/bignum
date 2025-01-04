#pragma once

#include <string>

namespace jp {

/**
 * Consolidated initialization appropriate for most executables. This function sets up logging,
 * command line flags, and similar systems.
 *
 * Usually this is called as the first line in main() as:
 *
 *   jp::initialize(&argc, &argv);
 *
 */
void initialize(int* argc, char** argv[], const std::string& log_dir = "/var/log/jp");

}  // namespace jp
