// compileExcel.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include "xlsxwriter.h"

using namespace std;

int main()
{

    /* Create a workbook and add a worksheet. */
    lxw_workbook *workbook = workbook_new("../../../tutorial01.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    /* Start from the first cell. Rows and columns are zero indexed. */
    int row = 0;
    int col = 0;

    /* Iterate over the data and write it out element by element. */
    for (row = 0; row < 4; row++) {
        //std::string st = "测试中文第二次";
        worksheet_write_string(worksheet, row, col, "中文", NULL);
        worksheet_write_number(worksheet, row, col + 1, row, NULL);
    }

    /* Write a total using a formula. */
    worksheet_write_string(worksheet, row, col, "Total", NULL);
    worksheet_write_formula(worksheet, row, col + 1, "=SUM(B1:B4)", NULL);

    //关闭工作簿
    workbook_close(workbook);


	cout << "Hello CMake. 你好" << endl;
	return 0;
}
