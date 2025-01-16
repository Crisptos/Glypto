find_package(SDL2 REQUIRED)

set(VENDOR_DIR "/vendor")
set(SRC_DIR "src")

add_library(Glypto 
  SHARED 
  ${SRC_DIR}/Defines.h 
  ${SRC_DIR}/GlyptoCore/Core.h 
  ${SRC_DIR}/GlyptoCore/Logger.h  
  ${SRC_DIR}/GlyptoCore/Logger.cpp 
)

target_include_directories(Glypto 
  PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Glypto SDL2::SDL2 SDL2::SDL2main)