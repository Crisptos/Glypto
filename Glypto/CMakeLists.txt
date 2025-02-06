find_package(SDL2 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

set(VENDOR_DIR "/vendor")
set(SRC_DIR "src")

file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp ${SRC_DIR}/*.h)

add_library(Glypto 
  SHARED 
  ${SOURCES}
)

target_include_directories(Glypto 
  PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Glypto SDL2::SDL2 SDL2::SDL2main spdlog::spdlog glad::glad glm::glm)