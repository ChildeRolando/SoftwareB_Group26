#include <iostream>
#include <Windows.h>
#pragma comment( linker, "/subsystem:windows /ENTRY:mainCRTStartup" )
//线程回调函数
//参数：程序名称
DWORD WINAPI ThreadCheckGuard(LPVOID lParam) {
	STARTUPINFOA si = { sizeof(si) };
	PROCESS_INFORMATION pi = { 0 };
	HANDLE hMutex;
	while (true) {
		hMutex = OpenMutexA(MUTEX_ALL_ACCESS, FALSE, (LPCSTR)lParam);
		if (!hMutex) {
		        //unicode下，用W版会失败
			CreateProcessA(
				(LPCSTR)lParam, 
				NULL, NULL, NULL,
				FALSE,
				CREATE_NO_WINDOW,
				NULL, NULL,
				&si, &pi);
			WaitForSingleObject(pi.hProcess, INFINITE);
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
			printf("检测到G1被结束，已成功唤醒\n");
		}
		else {
			CloseHandle(hMutex);
		}
		Sleep(500);
	}
}

int main()
{
	/* HWND hwnd; 
	if(hwnd=::FindWindow("ConsoleWindowClass",NULL)){ //找到bai控制台句柄
		::ShowWindow(hwnd,SW_HIDE); //隐藏控制台窗口
	} */
	DWORD Tid;
	//创建自己的互斥体对象
	CreateMutexA(NULL, TRUE, (LPCSTR)"G2.exe");
	//创建线程检测对方的互斥体
	CreateThread(NULL, 0, ThreadCheckGuard, (LPVOID*)"G1.exe", 0, &Tid);
	while (1) { Sleep(500); };
	return 0;
}