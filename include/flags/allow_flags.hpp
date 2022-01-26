#ifndef ENUM_CLASS_ALLOW_FLAGS_HPP
#define ENUM_CLASS_ALLOW_FLAGS_HPP


#include <type_traits>


namespace flags {

  template <typename T, typename = void>
  struct is_flags : std:false_type {};
  template <typename T>
  struct is_flags < T, decltype(enableEnumFlags(T{})) > : std::true_type {};

} // namespace flags


#define ALLOW_FLAGS_FOR_ENUM(Name) inline void enableEnumFlags(Name) {}
#define ALLOW_FLAGS_FOR_ENUM_IN_CLASS(Name) friend inline void enableEnumFlags(Name) {}


#endif // ENUM_CLASS_ALLOW_FLAGS_HPP
