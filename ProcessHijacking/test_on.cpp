// #include <Shlwapi.h>
// #pragma comment(lib,"shlwapi.lib")
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string file_name1,file_name2,s1,s2,s;
    s = "taskkill /IM ";
    s1 = "reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\";
    s2 = "\" /v debugger /t REG_SZ /d cmd.exe";
    cout<<"Wanna Ban:"<<endl;
    cin >> file_name1;
    file_name2 = file_name1;
    s1.append(file_name1.append(s2));
    s.append(file_name2);
    const char* commad = s1.data();
    system(commad);
    commad = s.data();
    system(commad);
    cout<<commad<<endl;
    system("taskkill /IM explorer.exe");
    //system("start explorer.exe");
    system("pause");
    return 0;
}
