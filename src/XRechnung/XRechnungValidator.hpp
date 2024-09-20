#pragma once

#include "XRechnung.hpp"

namespace XRechnung {
    class XRechnungValidator {
    public:
        virtual ~XRechnungValidator() = default;

        virtual bool validate(const Invoice &invoice) = 0;
    };
}// namespace XRechnung
