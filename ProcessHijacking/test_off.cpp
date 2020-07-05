// #include <Shlwapi.h>
// #pragma comment(lib,"shlwapi.lib")
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string file_name2;
    string s3 = "reg delete \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\";
    string s4 = "\" /v debugger";
    cout<<"Wanna unban:"<<endl;
    cin>>file_name2;
    s3.append(file_name2.append(s4));
    const char* commad = s3.data();
    system(commad);
    cout<<commad<<endl;
    system("taskkill /IM explorer.exe");
    //system("start explorer.exe");
    system("pause");
    return 0;
}
