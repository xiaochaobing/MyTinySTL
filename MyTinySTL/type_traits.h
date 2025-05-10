#ifndef MYTINYSTL_TYPE_TRAITS_H_
#define MYTINYSTL_TYPE_TRAITS_H_

// 这个头文件用于提取类型信息

// use standard header for type_traits
#include <type_traits>

namespace mystl
{

// helper struct

template <class T, T v>
//编译器封装常量
struct m_integral_constant
{
  static constexpr T value = v;
};

//bool特化
template <bool b>
using m_bool_constant = m_integral_constant<bool, b>;

typedef m_bool_constant<true>  m_true_type;
typedef m_bool_constant<false> m_false_type;

/*****************************************************************************************/
// type traits

// is_pair

// --- forward declaration begin前向声明：这个文件中没有具体实例，告诉编译器有这东西，减少文件的依赖，但不能使用这个类的示例，只能使用它的指针
template <class T1, class T2>
struct pair;
// 主模版
template <class T>
struct is_pair : mystl::m_false_type {};

//特化
template <class T1, class T2>
struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {};

} // namespace mystl

#endif // !MYTINYSTL_TYPE_TRAITS_H_

