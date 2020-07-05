#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <shellapi.h>

int main( void ){
    ShellExecuteA(NULL, "open", "G1.exe", NULL, NULL, SW_HIDE);
    return 1;
}