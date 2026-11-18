# components

个人 C++ 组件库，使用 CMake 构建。

## 构建与测试

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

项目使用 C++20 标准。组件将在 `include/components` 下按需添加，并在 `tests` 下添加对应测试。