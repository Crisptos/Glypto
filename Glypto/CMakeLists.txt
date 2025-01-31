find_package(SDL2 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

set(VENDOR_DIR "/vendor")
set(SRC_DIR "src")

add_library(Glypto 
  SHARED 
  ${SRC_DIR}/Defines.h 
  ${SRC_DIR}/GlyptoCore/Core.h
  ${SRC_DIR}/GlyptoCore/EntryPoint.h  
  ${SRC_DIR}/GlyptoCore/Logger.h  
  ${SRC_DIR}/GlyptoCore/Logger.cpp
  ${SRC_DIR}/GlyptoCore/Application.h
  ${SRC_DIR}/GlyptoCore/Application.cpp
  ${SRC_DIR}/GlyptoCore/Event.h 
  ${SRC_DIR}/GlyptoCore/InputManager.h 
  ${SRC_DIR}/GlyptoCore/InputManager.cpp
  ${SRC_DIR}/GlyptoCore/Platform.h
  ${SRC_DIR}/GlyptoCore/Platform.cpp  
)

target_include_directories(Glypto 
  PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Glypto SDL2::SDL2 SDL2::SDL2main spdlog::spdlog glad::glad)