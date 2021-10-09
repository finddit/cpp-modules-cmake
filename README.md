# cpp-modules-cmake
experimenting with c++20, modules and cmake

to build
```
git clone git@github.com:finddit/cpp-modules-cmake.git
mkdir build && cd build
/usr/local/bin/cmake --no-warn-unused-cli -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++ -G "Unix Makefiles" ..
make
```

then simply run
```
main
```

Happy coding! :)
