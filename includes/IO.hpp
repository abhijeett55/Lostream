#pragma once

#include <iostream>

namespace IO {
    template <typename T, typename CharT = std::char_traits<T>>
    std::basic_ostream<T, CharT>& endl(std::basic_ostream<T, CharT>& outputStream) {
        return outputStream << outputStream.widen('\n');
    }
}