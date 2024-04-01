#ifndef SORTABLE_H
#define SORTABLE_H
#include <concepts>

/* 
    Concept for types that support < and > operators

    Since sorting requires the operations "<" & ">" this concept
    ensures that the classes templating T have the operation
    "<" or ">"
*/
template <typename T>
concept Sortable = requires(T x, T y) {
    { x < y } -> std::convertible_to<bool>;
    { x > y } -> std::convertible_to<bool>;
};

#endif
