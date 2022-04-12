// Completely symmetric day.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int C_year(int B_year) {
    int A_year[4];
    for (int a = 0; a < 4; a++) {
        A_year[a] = B_year % 10;
        B_year = (B_year - B_year % 10) / 10;
    }
    return A_year[0] * 1000 + A_year[1] * 100 + A_year[2] * 10 + A_year[3];
}
bool J_year(int O_year) {
    int O_day = O_year % 100;
    int O_month = (O_year - O_day) / 100;
    int Month_b[] = { 1,3,5,7,8,10,12 };
    bool Month_big_j=false;
    if (O_month > 12 || O_month < 1) {
        return false;
    }
    if (O_month == 2) {
        if (O_year % 400 != 0 && O_year % 4 == 0 || O_year % 400 != 0) {
            return O_day <= 29 && O_day >= 1;
        }
        else
            return O_day <= 29 && O_day >= 1;
    }
    else if (O_month <= 12 && O_month > 0) {
        for (int a = 0; a < 7; a++) {
            if (O_month == Month_b[a]) {
                Month_big_j=true;
            }
        }
    }
    if (Month_big_j == true) {
        return O_day <= 31 && O_day >= 1;
    }
    else 
        return O_day <= 30 && O_day >= 1;
    }
int main()
{
    for (int Year = 1000; Year <= 9999; Year++) {
        int A_year = C_year(Year);
        if (J_year(A_year) == true)
            printf("%d\n", Year * 10000 + A_year);
    }
    system("pause");
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
