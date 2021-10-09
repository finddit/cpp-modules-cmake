#ervin@Ervins-MBP cpp-modules-cmake % clang++ -std=c++20 -fmodules-ts -c helloworld.cpp -Xclang -emit-module-interface -o helloworld.pcm
#ervin@Ervins-MBP cpp-modules-cmake % clang++ -std=c++20 -fmodules-ts -stdlib=libc++ -fprebuilt-module-path=. main.cpp helloworld.cpp 
#export CPLUS_INCLUDE_PATH=/Library/Developer/CommandLineTools/SDKs/MacOSX11.3.sdk/usr/include 

cmake_minimum_required(VERSION 3.20)
project(main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/modules)

function(add_module name)
    file(MAKE_DIRECTORY ${PREBUILT_MODULE_PATH})
    add_custom_target(${name}.pcm
            COMMAND
                ${CMAKE_CXX_COMPILER}
                -std=c++20
                -stdlib=libc++
                -fmodules-ts
                -c
                ${CMAKE_CURRENT_SOURCE_DIR}/${ARGN}
                -Xclang -emit-module-interface
                -o ${PREBUILT_MODULE_PATH}/${name}.pcm

            )
endfunction()


add_compile_options(-fmodules-ts)
add_compile_options(-std=c++20)
add_compile_options(-stdlib=libc++)
add_compile_options(-fprebuilt-module-path=${PREBUILT_MODULE_PATH})

add_module(helloworld helloworld.cpp)
add_module(math math.cpp)

set(source_files 
    main.cpp
    math.cpp
    helloworld.cpp
)

add_executable(main ${source_files})
add_dependencies(main helloworld.pcm math.pcm)

