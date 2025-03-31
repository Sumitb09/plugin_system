cmake_minimum_required(VERSION 3.8)
project(plugin_system)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(pluginlib REQUIRED)

add_library(string_reverser SHARED src/string_reverser.cpp)
ament_target_dependencies(string_reverser rclcpp pluginlib)
target_include_directories(string_reverser PUBLIC include)
pluginlib_export_plugin_description_file(plugin_system plugins.xml)

add_library(string_counter SHARED src/string_counter.cpp)
ament_target_dependencies(string_counter rclcpp pluginlib)
target_include_directories(string_counter PUBLIC include)
pluginlib_export_plugin_description_file(plugin_system plugins.xml)

add_executable(plugin_manager src/plugin_manager.cpp)
ament_target_dependencies(plugin_manager rclcpp pluginlib)
target_include_directories(plugin_manager PUBLIC include)

install(TARGETS plugin_manager string_reverser string_counter
        DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/ DESTINATION include)

ament_package()
