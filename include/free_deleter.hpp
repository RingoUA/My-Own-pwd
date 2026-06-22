#pragma once

namespace mopwd {
    struct FreeDeleter {
        void operator()(char* ptr) const noexcept;
    };
}
