# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("compileExcel")


include_directories(libs/libxlsxwriter/include)
include_directories(libs/libxlsxwriter/src)
include_directories(libs/zlib)


#-------- 用libxlsxwriter源码创建库，然后在主cmakelists中调用
# 将子目录添加到生成
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/libxlsxwriter/src)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR== " ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND XLSXWRITER_LIBS libxlsxwriter) #库名
list(APPEND XLSXWRITER_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/libs/libxlsxwriter/src")
#---------

add_executable (compileExcel "compileExcel.cpp")

target_link_libraries(compileExcel ${XLSXWRITER_LIBS})



#将包含目录添加到目标. 为什么需要这个？
target_include_directories(compileExcel PUBLIC
	
	 #建立接口。#include不能跟踪进文件时，在这里把相对路径加上
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs/libxlsxwriter/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs/libxlsxwriter/src>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs/zlib>

	${XLSXWRITER_INCLUDES}
)