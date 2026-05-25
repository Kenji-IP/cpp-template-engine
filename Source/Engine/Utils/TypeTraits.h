#pragma once

namespace Engine
{
    template <typename T, T V>
    struct ValueConstant
    {
        static constexpr T VALUE = V;
        using ValueType = T;
        using Type = ValueConstant;

        constexpr operator ValueType() const noexcept { return VALUE; }
        constexpr ValueType operator()() const noexcept { return VALUE; }
    };

    template <bool B>
    using BoolConstant = ValueConstant<bool, B>;

    using TrueType = BoolConstant<true>;
    using FalseType = BoolConstant<false>;

    template <typename T>
    struct IsLValueReference : FalseType {};

    template <typename T>
    struct IsLValueReference<T&> : TrueType {};

    template <typename T>
    inline constexpr bool IsLValueReference_V = IsLValueReference<T>::VALUE;

    template <typename T>
    struct IsRValueReference : FalseType {};

    template <typename T>
    struct IsRValueReference<T&&> : TrueType {};

    template <typename T>
    inline constexpr bool IsRValueReference_V = IsRValueReference<T>::VALUE;

    template <typename T>
    struct RemoveReference { using Type = T; };

    template <typename T>
    struct RemoveReference<T&> { using Type = T; };

    template <typename T>
    struct RemoveReference<T&&> { using Type = T; };

    template <typename T>
    using RemoveReference_T = typename RemoveReference<T>::Type;

    template <typename T>
    constexpr RemoveReference_T<T&&> Move(T&& t) noexcept
    {
        return static_cast<RemoveReference_T<T>>(t);
    }

    template <typename T>
    constexpr T&& Forward(RemoveReference_T<T>& t) noexcept
    {
        return static_cast<T&&>(t);
    }

    template <typename T>
    constexpr T&& Forward(RemoveReference_T<T>&& t) noexcept
    {
        static_assert(!IsLValueReference_V<T>, "Bad Forward Call!");
        return static_cast<T&&>(t);
    }
}