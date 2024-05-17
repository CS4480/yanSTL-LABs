namespace my
{

// ����T���пɽ���Args...����ʵ�εĹ��캯��ʱ�����档
template <typename T, typename... Args>
inline constexpr bool is_constructible_v = __is_constructible(T, Args...);


/// ����Ҫ�޸ı��ļ����������ݡ�

// ����TΪvoidʱ�����档
template <typename>
inline constexpr bool is_void_v = false;

// ����TΪ�������͡��ַ����͡���������ʱ�����档
template <typename>
inline constexpr bool is_integral_v = false;

// ����T���ж���volatile����ʱ�����档
template <typename>
inline constexpr bool is_volatile_v = false;

// ����TΪָ��ʱ�����档
template <typename>
inline constexpr bool is_pointer_v = false;

// ����TΪ����ʱ�����档
template <typename>
inline constexpr bool is_reference_v = false;

// ����TΪ����ʱ�����档��ʾ��ֻ��UΪ����������ʱ��is_const_v<const U>���ؼ١�
template <typename>
inline constexpr bool is_function_v = false;

// ����TΪ����void������������������κ�����ʱ�����档
template <typename>
inline constexpr bool is_object_v = false;

// ����TΪԭ������ʱ�����档
template <typename>
inline constexpr bool is_array_v = false;

// ����T�����Ĭ�Ϲ���ʱ�����档
template <typename>
inline constexpr bool is_default_constructible_v = false;

// ����T����ɿ�������ʱ�����档
template <typename>
inline constexpr bool is_copy_constructible_v = false;

// ����T������ƶ�����ʱ�����档
template <typename>
inline constexpr bool is_move_constructible_v = false;

// ����T1, T2����ͬ����ʱ�����档����CV���Ρ�
template <typename, typename>
inline constexpr bool is_same_v = false;

// ����TΪTypes...��������֮һʱ�����档�ⲻ�Ǳ�׼�涨�����ӡ�
template <typename, typename...>
inline constexpr bool is_any_of_v = false;

// ����T��ΪTypes...��������֮һʱ�����档�ⲻ�Ǳ�׼�涨�����ӡ�
template <typename, typename...>
inline constexpr bool is_none_of_v = false;

// ���ض�Ӧ�Ĵ���const���ε����͡�
template <typename>
using add_const_t = void;

// ���ض�Ӧ�Ĳ�����const���ε����͡�
template <typename>
using remove_const_t = void;

// ���ض�Ӧ�Ĳ�����CV���ε����͡�
template <typename>
using remove_cv_t = void;

// ���ض�Ӧ�ķ��������͡�
template <typename>
using remove_reference_t = void;

// ���ض�Ӧ����ֵ�������͡����������۵�����
template <typename>
using add_lvalue_reference_t = void;

// ���ض�Ӧ����ֵ�������͡����������۵�����
template <typename>
using add_rvalue_reference_t = void;

// ���ض�Ӧ�ķ��������͵�ָ�롣
template <typename>
using add_pointer_t = void;

// ��������T��ά�ȣ��������鷵��0��
template <typename>
inline constexpr size_t rank_v = 0;

// ��������T�ڵ�I��ά���ϵĴ�С��
template <typename, size_t>
inline constexpr size_t extent_v = 0;

// ��ȡ����T��Ԫ�ص����͡��������鷵���䱾��
template <typename>
using remove_extent_t = void;

// ����T���˻����͡�

template <typename>
struct decay { using type = void; };

/// ����� requires �Ӿ���Ա�֤�� T Ϊ����ʱ��ѡ���ģ�����ʵ������
/// ��Ҳ�����Լ���һ����ʹ�� requires �İ취��
template <typename T> requires is_function_v<T>
struct decay<T> { using type = void; };

template <typename T>
using decay_t = typename decay<T>::type;
}