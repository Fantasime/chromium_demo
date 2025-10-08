#include "base/command_line.h"
#include "base/logging.h"

// `VLOG()` means "verbose logging".
//
// 1. `VLOG()` levels can be adjusted on a per-module basis at runtime.
// 2. `VLOG()` takes an arbitrary integer value (higher numbers should be used
// for more verbose logging), so you can make your logging levels as granular as
// you wish.
//
// See: https://groups.google.com/a/chromium.org/g/chromium-dev/c/3NDNd1KzXeY
int main(int argc, char** argv) {
  // Initialize `CommandLine`.
  base::CommandLine::Init(argc, argv);

  // `VLOG()` will print nothing if no initializing.
  logging::InitLogging(logging::LoggingSettings());

  // Run `verbose_logging --v=<level>` to view following logs.
  VLOG(1) << "I'm printed when you run the program with --v=1 or more";
  VLOG(2) << "I'm printed when you run the program with --v=2 or more";
  VLOG(3) << "I'm printed when you run the program with --v=3 or more";
  VLOG(4) << "I'm printed when you run the program with --v=4 or more";

  return 0;
}
