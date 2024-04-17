### CPP 从C++11到C++20有什么改变
C++11:

- 自动类型推断（auto 关键字变量声明）
- 范围基础的 for 循环
- nullptr(代替原本的NULL)
- 强类型枚举
- 初始化列表
- Lambda 表达式(代替原本的仿函数)
- 智能指针
- 右值引用和移动语义
- 并发（线程、互斥、条件变量等）

c++14:

- 泛型lambda表达式（auto 关键字）
- 二进制字面量
- 函数，lambda返回类型推断
- 变量模板
- 数字分隔符

C++17:

- 结构化绑定
- if 和 switch 的初始化语句
- 内联变量
- std::optional, std::variant 和 std::any
- 文件系统库

C++20:

- 模块
- 概念（concepts）
- 协程
- 格式库（std::format）
- 三元比较运算符
- std::span

### 移动语义解决了什么问题

- 资源管理：在 C++ 中，动态分配的资源（如通过 new 分配的内存）需要手动释放。如果在复制这些资源时直接复制它们的值，那么就需要为新的副本分配新的资源，这会导致额外的资源消耗。而移动语义允许我们在不创建新资源的情况下将资源从一个对象转移到另一个对象。

- 性能优化：在某些情况下，如返回局部对象或从函数中抛出异常时，对象需要被复制。如果对象包含大量数据，那么复制这些对象可能会非常耗时。而移动语义允许我们在这些情况下移动对象，而不是复制对象，从而提高性能。

### const 左值引用有什么特性
- 绑定到右值：const 左值引用可以绑定到右值。这是一种常用的技巧，用于在函数参数中接受右值，从而避免不必要的对象复制

- 不能修改引用的对象：由于 const 左值引用引用的对象是 const 的，因此不能通过 const 左值引用来修改引用的对象。

- 延长临时对象的生命周期：const 左值引用可以延长临时对象（即右值）的生命周期。临时对象的生命周期会被延长到与 const 左值引用的生命周期相同。

- 作为函数重载的一部分：const 左值引用常常用于函数重载，以区分左值和右值。例如，你可以定义两个重载的函数，一个接受 const T& 参数（用于左值和右值），另一个接受 T&& 参数（仅用于右值）。

### constexpr与const关键字的区别，可以对constexpr变量取地址吗

constexpr 和 const 都是 C++ 中的常量修饰符，但它们有一些重要的区别：

编译时 vs 运行时：constexpr 指定的变量或函数必须在编译时就能确定值，因此它们常常用于模板元编程、编译时计算等场景。而 const 变量的值可以在运行时确定，只要在初始化后不再改变就可以。

常量表达式：constexpr 修饰的变量必须是一个常量表达式，即它的值必须在编译时就能确定。而 const 修饰的变量只要在初始化后不再改变就可以，它的值可以在运行时确定。

函数：constexpr 也可以修饰函数，表示该函数在给定常量表达式参数时能产生常量表达式结果。而 const 不能修饰函数（但可以修饰成员函数，表示该成员函数不会修改它所属的对象）。

可以对 constexpr 变量取地址。constexpr 变量在内存中有实际的存储位置，因此可以获取它们的地址。

### const 变量可以改值吗，什么情况下用const_cast是ub什么时候不是ub

const_cast 是 C++ 中的一种类型转换运算符，它可以用来移除对象的 const 属性。但是，使用 const_cast 改变原本就是 const 的对象的值是未定义行为。然而，如果对象原本就是非 const 的，那么使用 const_cast 移除 const 属性并改变其值是合法的。
```
int x = 10;
const int* cp = &x;
int* p = const_cast<int*>(cp);
*p = 20;  // 合法，因为 x 是一个非 const 对象
```

### dynamic_cast怎么知道转换到子类的

RTTI（运行时类型信息）是 C++ 提供的一种机制，它允许在运行时查询和操作对象的类型。RTTI 包括 dynamic_cast 和 typeid 运算符，以及 std::type_info 类型。

RTTI 的工作原理如下：

类型信息：对于每个多态类型（即，包含虚函数的类），编译器都会生成一个类型信息对象（std::type_info）。这个对象包含了类型的名称和其他信息。

虚函数表：每个多态类型的对象都有一个指向虚函数表（vtable）的指针。虚函数表是一个包含了该类型的所有虚函数地址的数组。在这个表中，还包含了一个指向类型信息对象的指针。

dynamic_cast：dynamic_cast 运算符可以在类的继承层次中进行安全的向下转型。它通过比较源对象和目标类型的类型信息来检查转换是否有效。

typeid：typeid 运算符可以获取一个对象的类型信息。它通过访问对象的虚函数表来获取类型信息对象。

从编译器的角度来看，实现 RTTI 主要涉及到生成类型信息对象和虚函数表，以及实现 dynamic_cast 和 typeid 运算符。这些都需要在编译时进行，因此对编译器的实现有一定的复杂性。
template<Sortable T>
void sortAndPrint(T& container) {
    std::sort(container.begin(), container.end());
    for (const auto& item : container) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}
### RAII
RAII（Resource Acquisition Is Initialization）是一种编程技术，它将资源的获取与初始化绑定在一起，将资源的释放与对象的生命周期绑定在一起。RAII 的主要好处是它可以自动管理资源，避免资源泄漏。当对象被销毁（例如，出了作用域或被 delete）时，其析构函数会自动被调用，从而释放资源。这样，程序员就不需要手动管理资源，可以避免许多由于忘记释放资源导致的问题。
如果不使用 RAII，那么在以下情况下容易发生内存泄漏：

- 忘记释放资源：如果你手动获取了资源（例如，使用 new 分配了内存），但忘记释放它（例如，忘记调用 delete），那么就会发生内存泄漏。

- 异常：如果在释放资源之前发生了异常，那么资源的释放代码可能就不会被执行，从而导致内存泄漏。

- 复杂的控制流：如果控制流很复杂，那么可能在某些路径上忘记释放资源，从而导致内存泄漏。

对于内存管理，可以使用以下几点来保证：

- 使用智能指针：智能指针（如 std::unique_ptr 和 std::shared_ptr）是 RAII 的一种实现，它们可以自动管理动态分配的内存。

- 使用容器：C++ 的容器（如 std::vector 和 std::string）也是 RAII 的一种实现，它们可以自动管理内存。

- 尽量避免手动管理资源：如果可能，尽量避免手动使用 new 和 delete。如果必须使用，确保在每个 new 对应一个 delete。

- 使用异常安全的代码：确保你的代码在异常发生时仍然能正确释放资源。

### C++异常
C++异常是一种在程序运行时处理错误的机制。当在程序中发生某种错误时，可以抛出一个异常。然后，在调用堆栈的上层，可以捕获并处理这个异常（即try-catch），同时会返回错误码。
错误码的好处：

- 简单：错误码是一种简单的错误处理方式，只需要返回一个表示错误类型的值即可。

- 跨语言：错误码可以在不同的编程语言之间使用，不需要特殊的语言支持。

错误码的弊端：

- 易错：使用错误码需要程序员记住检查每个可能返回错误码的函数调用，这很容易出错。

- 代码混乱：错误处理代码和正常的业务逻辑代码混在一起，使得代码难以阅读和维护。

noexcept 关键字指定一个函数不会抛出异常。这对于优化代码和提高性能非常有用，因为编译器可以做出一些假设来生成更优的代码。

在 C++ 标准库中，许多函数和操作都被声明为 noexcept。例如，移动构造函数和移动赋值操作符通常应该是 noexcept 的，因为它们不应该抛出异常。如果移动构造函数不是 noexcept，那么在某些情况下，C++ 标准库的某些函数和容器可能会选择调用拷贝构造函数，而不是移动构造函数。

例如，std::vector 的 resize 和 push_back 方法在需要重新分配内存时，如果元素的移动构造函数是 noexcept，那么它会移动元素到新的内存。但是，如果移动构造函数可能抛出异常（即，不是 noexcept），那么 std::vector 会选择调用拷贝构造函数，因为这样更安全。

### C++20对模板是不是有什么替代的做法
C++20引入了一种新的特性，叫做概念（Concepts），它可以被视为对模板的一种补充或者替代。

概念可以用来定义一组要求，这些要求描述了一个模板参数必须满足的接口（即，它必须具有哪些类型、函数、操作符等）。然后，你可以在模板定义中使用这个概念，来限制模板参数的类型。

例如，你可以定义一个 Sortable 概念，要求一个类型必须可以用 std::sort 排序：
```
template<typename T>
concept Sortable = requires(T a) {
    std::sort(a.begin(), a.end());
};
```
在模板定义中使用这个概念：
```
template<Sortable T>
void sortAndPrint(T& container) {
    std::sort(container.begin(), container.end());
    for (const auto& item : container) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}
```

### SFINAE
如果一个模板替换失败，那么这不是一个错误，编译器会忽略这个模板，并尝试下一个模板。

定义两个函数模板，一个处理指针类型，一个处理其他类型：
```
template<typename T>
auto print(T t) -> typename std::enable_if<std::is_pointer<T>::value>::type {
    std::cout << "Pointer: " << *t << '\n';
}

template<typename T>
auto print(T t) -> typename std::enable_if<!std::is_pointer<T>::value>::type {
    std::cout << "Non-pointer: " << t << '\n';
}
```

### CRTP
CRTP，全称为Curiously Recurring Template Pattern（奇异递归模板模式），是一种在C++中使用模板来实现静态多态性的技术。

在CRTP中，一个类 Derived 继承自一个模板基类 Base，并将自身作为模板参数传递给 Base。例如：

```
template <typename Derived>
class Base {
    // ...
};

class Derived : public Base<Derived> {
    // ...
};
```
Base 类就可以在编译时知道其派生类的类型，从而能够调用派生类的函数或访问其成员。这种方式避免了虚函数带来的运行时开销，因为所有的函数调用都在编译时被解析。

CRTP常常用于实现静态多态性、提供默认实现、生成编译时错误等。例如，你可以使用CRTP来实现一个可复制的混入类：
```
template <typename Derived>
class Copyable {
public:
    Derived clone() const {
        return static_cast<const Derived&>(*this).cloneImpl();
    }
};

class MyClass : public Copyable<MyClass> {
public:
    MyClass cloneImpl() const {
        // 实现复制逻辑
    }
};
```
不能处理的情况：如果你有一个基类指针，它可以指向多个不同的派生类对象，然后你要通过这个指针调用虚函数，那么你就不能使用CRTP来消除这个虚函数调用。


### map采用find操作之后erase了,可能对遍历容器有什么影响
在C++的std::map中，erase函数会删除指定的元素，并使指向被删除元素的迭代器失效。遍历std::map的过程中使用erase删除元素，那么你需要特别小心，以避免迭代器失效导致的未定义行为。

### 底层锁是怎么实现的
底层的锁实现通常依赖于操作系统提供的原语，例如在Linux中，可能会使用pthread_mutex_t来实现互斥锁。这些原语通常是由操作系统内核提供的，能够保证在多线程或多进程环境中的原子性。