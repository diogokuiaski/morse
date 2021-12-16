add_executable(cmorse main.cpp)
target_compile_features(cmorse PRIVATE cxx_std_17)
target_link_libraries(cmorse PRIVATE morse fmt::fmt)