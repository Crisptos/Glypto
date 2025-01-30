cmake_minimum_required(VERSION 3.15)
set(VCPKG_MANIFEST_MODE ON)
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
project(Glypto)

add_subdirectory(Glypto)
add_subdirectory(Testbed)

if(WIN32)
    target_compile_definitions(Glypto 
      PRIVATE
      GLYPTO_PLATFORM_WINDOWS
    )

    target_compile_definitions(Testbed 
      PRIVATE
      GLYPTO_PLATFORM_WINDOWS
    )

    target_compile_definitions(Glypto 
      PRIVATE
      GLYPTO_BUILD_DLL
    )
endif()