#include "free_deleter.hpp"

#include <cstdlib>

namespace mopwd {
    void FreeDeleter::operator()(char* ptr) const noexcept {
        std::free(ptr);
    }
}
