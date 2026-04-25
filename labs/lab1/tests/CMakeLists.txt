set(TESTS
    test_rect_basic_methods
    test_rect_properties
    test_rect_operations
    test_bounding_rect
)

foreach(test_name ${TESTS})
    add_executable(${test_name} ${test_name}.cpp)
    target_link_libraries(${test_name} PRIVATE lab1_library)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()