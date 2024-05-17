namespace my
{

// ����T���пɽ���Args...����ʵ�εĹ��캯��ʱ�����档
template <typename T, typename... Args>
inline constexpr bool is_constructible_v = __is_constructible(T, Args...);


/// ����Ҫ�޸ı��ļ����������ݡ�

// ����TΪvoidʱ�����档
template <typename> inline constexpr bool is_void_v                      = false;
template <>         inline constexpr bool is_void_v<void>                = true;
template <>         inline constexpr bool is_void_v<const void>          = true;
template <>         inline constexpr bool is_void_v<volatile void>       = true;
template <>         inline constexpr bool is_void_v<const volatile void> = true;

// ���ض�Ӧ�Ĵ���const���ε����͡�
template <typename T> using add_const_t = const T;

// ���ض�Ӧ����ֵ�������͡����������۵�����
template <typename T> using add_lvalue_reference_t = T&;

// ���ض�Ӧ����ֵ�������͡����������۵�����
template <typename T> using add_rvalue_reference_t = T&&;

// ���ض�Ӧ�ķ��������͡�
template <typename T> struct remove_reference      { using type = T; };
template <typename T> struct remove_reference<T&>  { using type = T; };
template <typename T> struct remove_reference<T&&> { using type = T; };
template <typename T> using  remove_reference_t = typename remove_reference<T>::type;

// ���ض�Ӧ�ķ��������͵�ָ�롣
template <typename T> using add_pointer_t = remove_reference_t<T>*;

// ����T1, T2����ͬ����ʱ�����档����CV���Ρ�
template <typename, typename> inline constexpr bool is_same_v = false;
template <typename T>         inline constexpr bool is_same_v<T, T> = true;

// ����TΪTypes...��������֮һʱ�����档�ⲻ�Ǳ�׼�涨�����ӡ�
template <typename T, typename... Types> inline constexpr bool is_any_of_v = (is_same_v<T, Types> || ...);

// ����T��ΪTypes...��������֮һʱ�����档�ⲻ�Ǳ�׼�涨�����ӡ�
template <typename T, typename... Types> inline constexpr bool is_none_of_v = !is_any_of_v<T, Types...>;

// ���ض�Ӧ�Ĳ�����CV���ε����͡�
template <typename T> struct remove_cv                   { using type = T; };
template <typename T> struct remove_cv<const T>          { using type = T; };
template <typename T> struct remove_cv<volatile T>       { using type = T; };
template <typename T> struct remove_cv<const volatile T> { using type = T; };
template <typename T> using  remove_cv_t = typename remove_cv<T>::type;

// ����TΪ�������͡��ַ����͡���������ʱ�����档
template <typename T> inline constexpr bool is_integral_v = is_any_of_v<remove_cv_t<T>, bool, char, signed char, unsigned char, char8_t, char16_t, char32_t, wchar_t, short, unsigned short, int, unsigned, long, unsigned long, long long, unsigned long long>;

// ����T���ж���const����ʱ�����档
template <typename>   inline constexpr bool is_const_v          = false;
template <typename T> inline constexpr bool is_const_v<const T> = true;

// ����T���ж���volatile����ʱ�����档
template <typename>   inline constexpr bool is_volatile_v             = false;
template <typename T> inline constexpr bool is_volatile_v<volatile T> = true;

// ����TΪָ��ʱ�����档
template <typename>   inline constexpr bool is_pointer_v                    = false;
template <typename T> inline constexpr bool is_pointer_v<T*>                = true;
template <typename T> inline constexpr bool is_pointer_v<T* const>          = true;
template <typename T> inline constexpr bool is_pointer_v<T* volatile>       = true;
template <typename T> inline constexpr bool is_pointer_v<T* const volatile> = true;

// ����TΪ����ʱ�����档
template <typename>   inline constexpr bool is_reference_v      = false;
template <typename T> inline constexpr bool is_reference_v<T&>  = true;
template <typename T> inline constexpr bool is_reference_v<T&&> = true;

// ����TΪ����ʱ�����档��ʾ��ֻ��UΪ����������ʱ��is_const_v<const U>���ؼ١�
template <typename T> inline constexpr bool is_function_v = !is_const_v<const T> && !is_reference_v<T>;

// ����TΪ����void������������������κ�����ʱ�����档
template <typename T> inline constexpr bool is_object_v = !is_void_v<T> && !is_function_v<T> && !is_reference_v<T>;

// ����TΪԭ������ʱ�����档
template <typename>             inline constexpr bool is_array_v       = false;
template <typename T, size_t N> inline constexpr bool is_array_v<T[N]> = true;
template <typename T>           inline constexpr bool is_array_v<T[]>  = true;

// ����T�����Ĭ�Ϲ���ʱ�����档
template <typename T> inline constexpr bool is_default_constructible_v = is_constructible_v<T>;

// ����T����ɿ�������ʱ�����档
template <typename T> inline constexpr bool is_copy_constructible_v = is_constructible_v<T, add_lvalue_reference_t<add_const_t<T>>>;

// ����T������ƶ�����ʱ�����档
template <typename T> inline constexpr bool is_move_constructible_v = is_constructible_v<T, add_rvalue_reference_t<T>>;

// ���ض�Ӧ�Ĳ�����const���ε����͡�
template <typename T> struct remove_const          { using type = T; };
template <typename T> struct remove_const<const T> { using type = T; };
template <typename T> using  remove_const_t = typename remove_const<T>::type;

// ��������T��ά�ȣ��������鷵��0��
template <typename T>           inline constexpr size_t rank_v       = 0;
template <typename T, size_t N> inline constexpr size_t rank_v<T[N]> = rank_v<T> + 1;
template <typename T>           inline constexpr size_t rank_v<T[]>  = rank_v<T> + 1;

// ��������T�ڵ�I��ά���ϵĴ�С��
template <typename T, size_t I>           inline constexpr size_t extent_v          = 0;
template <typename T, size_t N>           inline constexpr size_t extent_v<T[N], 0> = N;
template <typename T, size_t I, size_t N> inline constexpr size_t extent_v<T[N], I> = extent_v<T, I - 1>;
template <typename T, size_t I>           inline constexpr size_t extent_v<T[], I>  = extent_v<T, I - 1>;
template <typename T>                     inline constexpr size_t extent_v<T[], 0>  = 0;

// ��ȡ����T��Ԫ�ص����͡��������鷵���䱾��
template <typename T>           struct remove_extent       { using type = T; };
template <typename T>           struct remove_extent<T[]>  { using type = T; };
template <typename T, size_t N> struct remove_extent<T[N]> { using type = T; };
template <typename T> using remove_extent_t = typename remove_extent<T>::type;

std::decay<int>;
// ����T���˻����͡�
template <typename T>                           struct decay       { using type = remove_cv_t<T>; };
template <typename T>                           struct decay<T&>   { using type = typename decay<T>::type; };
template <typename T>                           struct decay<T&&>  { using type = typename decay<T>::type; };
template <typename T>                           struct decay<T[]>  { using type = typename decay<add_pointer_t<T>>::type; };
template <typename T, size_t N>                 struct decay<T[N]> { using type = typename decay<add_pointer_t<T>>::type; };
template <typename T> requires is_function_v<T> struct decay<T>    { using type = typename decay<add_pointer_t<T>>::type; };
template <typename T> using  decay_t = typename decay<T>::type;

}