# Notes 

Dependencies I have installed: `ninja llvm googletest`

When using the default Doxyfile, the following changes were made:
```txt
GENERATE_XML = YES
RECURSIVE = YES
```

```
cd build; ctest
```

To keep a clean root directory, keep all CMake files in the `build` directory:
```Bash
cd ./build
cmake -G Ninja ..

# To generate documentation
cmake --build ./build --target generate_docs
```

