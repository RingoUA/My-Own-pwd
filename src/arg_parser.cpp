#include "arg_parser.hpp"

#include <string_view>

namespace mopwd {
    Command parse_args(int argc, char** argv) {
        if (argc == 1) return mopwd::Command::LOGICAL;
        std::string_view arg = argv[1];
        if (arg == "-h" || arg == "--help") {
            return mopwd::Command::HELP;
        } else if (arg == "-v" || arg == "--version") {
            return mopwd::Command::VERSION;
        } else if (arg == "-L" || arg == "--logical") {
            return mopwd::Command::LOGICAL;
        } else if (arg == "-P" || arg == "--physical") {
            return mopwd::Command::PHYSICAL;
        }
        return mopwd::Command::HELP;
    }
}
