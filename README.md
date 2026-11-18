# components

个人 C++ 组件库，使用 CMake 构建。

## 组件

- `components/string_utils.hpp`：字符串修剪、分割和拼接

## 构建与测试

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```