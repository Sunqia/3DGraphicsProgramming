:@echo off

set input_path=%cd%

mkdir conv

: 方法一：先将input_path路径中的包含Kite和1280x640的文件名存入name.txt中，再使用for循环读
dir %input_path%\*.fx /b/od > %input_path%\conv\name.txt
dir %input_path%\*.glfs /b/od >> %input_path%\conv\name.txt
dir %input_path%\*.glpp /b/od >> %input_path%\conv\name.txt
dir %input_path%\*.hlsl /b/od >> %input_path%\conv\name.txt
dir %input_path%\*.glvp /b/od >> %input_path%\conv\name.txt
dir %input_path%\*.h /b/od >> %input_path%\conv\name.txt
dir %input_path%\*.cpp /b/od >> %input_path%\conv\name.txt
dir %input_path%\*.shader /b/od >> %input_path%\conv\name.txt

:~ni的作用是去掉文件名中的格式后缀，例如 %%i 是aa.264，则%%~ni就是aa。
for /F %%i in (%input_path%\conv\name.txt) do (
E:\Octave\Octave-5.1.0.0\mingw64\bin\iconv.exe -f Big5 -t utf-8 %input_path%\%%i > %input_path%\conv\%%i)

copy %input_path%\conv\*.* %input_path%

