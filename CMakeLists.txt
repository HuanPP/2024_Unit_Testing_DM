cmake_minimum_required(VERSION 3.10)
project(RelationProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 添加 Google Test 库
find_package(GTest REQUIRED)
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# 添加 Relation.cpp 和 RelationTest.cpp 构建 RelationTest 测试可执行文件
add_executable(RelationTest Relation.cpp RelationTest.cpp)
target_link_libraries(RelationTest /opt/homebrew/lib/libgtest.a /opt/homebrew/lib/libgtest_main.a pthread)

# 添加 main.cpp 和 Relation.cpp 构建主程序可执行文件
add_executable(MainApp main.cpp Relation.cpp)