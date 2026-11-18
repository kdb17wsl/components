# components

个人 C++ 组件库，使用 CMake 构建。

## 构建与测试

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

项目使用 C++20 标准。

组件放在 `src` 下，并将同一组件的 `.h` 和 `.cpp` 文件放在同一目录中，例如：

```text
src/
└── example/
    ├── example.h
    └── example.cpp
```

对应测试放在 `tests` 下。CMake 会自动收集 `src` 下的 `.cpp` 文件。