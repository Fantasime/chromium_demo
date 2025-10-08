#include "base/logging.h"
#include "base/logging/log_severity.h"

bool DoProcedure() {
  LOG(WARNING) << "Calling `DoProcedure()`...";
  return true;
}

int main(int argc, char** argv) {
  // Basic usage.
  //
  // See "base/logging/log_severity.h" for |severity|.
  //
  // `DLOG()` will work in "debug mode".
  LOG(INFO) << "Hello World!";
  DLOG(INFO) << "Debug World!";

  logging::SetMinLogLevel(logging::LOGGING_WARNING);
  LOG(INFO) << "You won't see this.";
  LOG(WARNING) << "WARNING!";
  logging::SetMinLogLevel(logging::LOGGING_INFO);

  // Conditional Logging.
  //
  // WARNING: |condition| will not be evaluated if:
  // 1. The |severity| is lower than set level.
  // 2. `DLOG_IF()` is used while not in "debug mode".
  int x = 37;
  LOG_IF(INFO, x & 1) << "You can see this if x is odd, x is " << x;
  LOG_IF(INFO, ~x & 1) << "You can see this if x is even, x is " << x;
  DLOG_IF(INFO, DoProcedure()) << "You can see this in \"debug mode\".";

  logging::SetMinLogLevel(logging::LOGGING_WARNING);
  LOG_IF(INFO, DoProcedure()) << "You won't see this.";
  LOG_IF(WARNING, DoProcedure()) << "DoProcedure() returned.";
  logging::SetMinLogLevel(logging::LOGGING_INFO);

  // Set log prefix.
  logging::SetLogPrefix("crdemo");
  LOG(INFO) << "I'm `basic_logging`";

  // Show more log items.
  logging::SetLogItems(true, true, true, true);
  LOG(INFO) << "Hello World!!!";

  return 0;
}
