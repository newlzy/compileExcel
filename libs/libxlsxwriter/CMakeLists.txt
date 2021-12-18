

#PROJECT_SOURCE_DIR：好像是子目录的根目录。工程的根目录
set(header_path "${CMAKE_CURRENT_SOURCE_DIR}/library/excel/libxlsxwriter/include")
set(header ${header_path}/xlsxwriter.h)
message(STATUS "PROJECT_SOURCE_DIR的值--  ${PROJECT_SOURCE_DIR}")
message(STATUS "header_path的值--  ${header_path}")

set(src
	app.c
	chart.c
	chartsheet.c
	comment.c
	content_types.c
	core.c
	custom.c
	drawing.c
	format.c
	hash_table.c
	Makefile
	metadata.c
	packager.c
	relationships.c
	shared_strings.c
	styles.c
	table.c
	theme.c
	utility.c
	vml.c
	workbook.c
	worksheet.c
	xmlwriter.c
)

set(in1
	app.h
	chart.h
	chartsheet.h
	comment.h
	common.h
	content_types.h
	core.h
	custom.h
	drawing.h
	format.h
	hash_table.h
	metadata.h
	packager.h
	relationships.h
	shared_strings.h
	styles.h
	table.h
	theme.h
	third_party
	utility.h
	vml.h
	workbook.h
	worksheet.h
	xmlwriter.h
	emyg_dtoa.h
	ioapi.h
	md5.h
	queue.h
	tmpfileplus.h
	tree.h
	zip.h
)
message(STATUS "header 值 --  ${header}")
message(STATUS "src 值 --  ${src}")



#add_library(libxlsxwriter ${header} ${in1} ${src})



