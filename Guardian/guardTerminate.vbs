On Error Resume Next  
'vbs代码开始----------------------------------------------  
sub Close_Process(ProcessName)  
On Error Resume Next  
     for each ps in getobject("winmgmts:\\.\root\cimv2:win32_process").instances_ '循环进程  
           if Ucase(ps.name)=Ucase(ProcessName) then  
                 ps.terminate  
           end if  
     next  
end sub  
Close_Process("G1.exe") 
Close_Process("G2.exe") 
Close_Process("G1.exe") 
Close_Process("G2.exe") 
Close_Process("G1.exe") 
Close_Process("G2.exe") 
Close_Process("G1.exe") 
Close_Process("G2.exe") 
Close_Process("G1.exe") 
Close_Process("G2.exe") 