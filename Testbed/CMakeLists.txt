add_executable(Testbed "src/TestbedClient.cpp")
target_include_directories(Testbed PRIVATE ${CMAKE_SOURCE_DIR}/Glypto/src)
target_link_libraries(Testbed PRIVATE Glypto)

add_dependencies(Testbed Glypto)

add_custom_command(TARGET Testbed POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "$<TARGET_FILE:Glypto>"
    "$<TARGET_FILE_DIR:Testbed>"
)