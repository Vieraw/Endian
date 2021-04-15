#ifndef ENDIAN_NUMBER_HPP
#define ENDIAN_NUMBER_HPP

#include "details/load.hpp"
#include "details/store.hpp"

#pragma pack(push, 1)

namespace endian {
    template<typename Type, details::order Order>
    class number {
    public:
        number() noexcept = default;

        number(Type t) noexcept {
            *this = t;
        }

        template<typename T, details::order O>
        number(number<T, O> t) {
            *this = t;
        }

        template<typename T, details::order O>
        number &operator=(number<T, O> t) noexcept {
            details::endian_store<Type, Order>(bytes_, static_cast<Type>(t.value()));
            return *this;
        }

        number &operator=(Type t) noexcept {
            details::endian_store<Type, Order>(bytes_, t);
            return *this;
        }

        operator Type() const {
            return value();
        }

        Type operator+() const noexcept {
            return value();
        }

        number &operator+=(Type y) noexcept {
            *this = static_cast<Type>(value() + y);
            return *this;
        }

        number &operator-=(Type y) noexcept {
            *this = static_cast<Type>(value() - y);
            return *this;
        }

        number &operator*=(Type y) noexcept {
            *this = static_cast<Type>(value() * y);
            return *this;
        }

        number &operator/=(Type y) noexcept {
            *this = static_cast<Type>(value() / y );
            return *this;
        }

        number &operator%=(Type y) noexcept {
            *this = static_cast<Type>(value() % y );
            return *this;
        }

        number &operator&=(Type y) noexcept {
            *this = static_cast<Type>(value() & y );
            return *this;
        }

        number &operator|=(Type y) noexcept {
            *this = static_cast<Type>(value() | y );
            return *this;
        }

        number &operator^=(Type y) noexcept {
            *this = static_cast<Type>(value() ^ y );
            return *this;
        }

        number &operator<<=(Type y) noexcept {
            *this = static_cast<Type>(value() << y );
            return *this;
        }

        number &operator>>=(Type y) noexcept {
            *this = static_cast<Type>(value() >> y );
            return *this;
        }

        number &operator++() noexcept {
            *this += 1;
            return *this;
        }

        number &operator--() noexcept {
            *this -= 1;
            return *this;
        }

        number operator++(int) noexcept {
            number tmp(*this);
            *this += 1;
            return tmp;
        }

        number operator--(int) noexcept {
            number tmp(*this);
            *this -= 1;
            return tmp;
        }

        template<class Ch, class Tr>
        friend std::basic_ostream <Ch, Tr> &operator<<(std::basic_ostream <Ch, Tr> &os, number const &x) {
            return os << x.value();
        }

        template<class Ch, class Tr>
        friend std::basic_istream <Ch, Tr> &operator>>(std::basic_istream <Ch, Tr> &is, number &x) {
            Type i;
            if (is >> i) {
                x = i;
            }

            return is;
        }

        Type value() const noexcept {
            return details::endian_load<Type, Order>(bytes_);
        }

        [[nodiscard]] unsigned char const *data() const noexcept {
            return bytes_;
        }

        unsigned char *data() noexcept {
            return bytes_;
        }

    private:
        union {
            unsigned char bytes_[sizeof(Type)]{};
            Type raw_value_;
        };
    };
}
#pragma pack(pop)
#endif