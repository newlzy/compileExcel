
set(header_path "${PROJECT_SOURCE_DIR}/libs/libxlsxwriter/include")

#set(md5 "${PROJECT_SOURCE_DIR}/libs/libxlsxwriter/third_party/minizip")

set(header ${header_path}/xlsxwriter.h)


#zlib库源码
set(zpl_h "${PROJECT_SOURCE_DIR}/libs/zlib/zlib.h")
set(zconf "${PROJECT_SOURCE_DIR}/libs/zlib/zconf.h")


message(STATUS "PROJECT_SOURCE_DIR值：" ${PROJECT_SOURCE_DIR})
message(STATUS "header_path ==  " ${header_path})
message(STATUS "header==  " ${header})
message(STATUS "zpl_h==  " ${zpl_h})


#------------ 获取目录下的所有文件名
file(GLOB excelname *.c) 
list(APPEND GAME_SOURCE_MINE ${excelname})
message(STATUS "GAME_SOURCE_MINE 值：" ${GAME_SOURCE_MINE})

#如果我们不但在当前目录需要引入，还需要在当前目录子目录引入了，这里就直接使用GLOB_RECURSE 递归
file(GLOB_RECURSE thirdparty ${PROJECT_SOURCE_DIR}/libs/libxlsxwriter/third_party/*.c)
message(STATUS "thirdparty 值：" ${thirdparty})


#开始循环
foreach(tempname ${excelname})
	message(STATUS "tempname 值：" ${tempname})
	
endforeach() #结束循环

#------------


#可以逐个名字添加进去，也可以用上面的方法获取目录下所有文件名存在一个变量中
set(src

	../third_party/minizip/md5.c
	../third_party/minizip/emyg_dtoa.c
	../third_party/minizip/ioapi.c
	../third_party/minizip/iowin32.c
	../third_party/minizip/miniunz.c
	../third_party/minizip/minizip.c
	../third_party/minizip/mztools.c
	../third_party/minizip/tmpfileplus.c
	../third_party/minizip/unzip.c
	../third_party/minizip/zip.c
)

set(zlibsrc
	../../zlib/adler32.c
	../../zlib/compress.c
	../../zlib/crc32.c
	../../zlib/deflate.c
	../../zlib/gzclose.c
	../../zlib/gzlib.c
	../../zlib/gzread.c
	../../zlib/gzwrite.c
	../../zlib/infback.c
	../../zlib/inffast.c
	../../zlib/inflate.c
	../../zlib/inftrees.c
	../../zlib/trees.c
	../../zlib/uncompr.c
	../../zlib/zutil.c
)

message(STATUS "src 值 --  ${src}")
message(STATUS "zlibsrc 值 --  ${zlibsrc}")
add_library(libxlsxwriter ${header} ${zpl_h} ${md5} ${zconf} ${GAME_SOURCE_MINE} ${thirdparty} ${zlibsrc})

