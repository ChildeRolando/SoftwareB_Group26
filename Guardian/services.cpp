
#include <iostream>
#include <Windows.h>
#include <ctime>

int main()
{
	DWORD Tid;
	//创建自己的互斥体对象
	CreateMutexA(NULL, TRUE, (LPCSTR)"p1.exe");
	while (1) {
    // 基于当前系统的当前日期/时间
    time_t now = time(0);
    // 把 now 转换为字符串形式
    char* dt = ctime(&now);
    std::cout << "local date&time: " << dt << std::endl;
		Sleep(2000);
  };
	return 0;
}