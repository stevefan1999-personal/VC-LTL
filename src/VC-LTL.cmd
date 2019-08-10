rem @echo off

::�Զ�����VC-LTL��

::ʹ��64λ���빤�ߣ���������
set PreferredToolArchitecture=x64

set Path=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE;C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build;%Path%

::�����ɾ�̬��
call:Build Static "x86 x64 ARM ARM64"

call:Build Static_Spectre "x86 x64 ARM ARM64"

call:Build Static_WinXP "x86 x64"

call:Build Static_WinXP_Spectre "x86 x64"

::���ɶ�̬UCRT��
call:Build Redist "x86 x64 ARM ARM64" "ucrt\ucrt.vcxproj"
::call:Build Dynamic "x86 x64 ARM ARM64" "ucrt\ucrt.vcxproj"



::���� CRT

call:BuildCRT 14.0.23918 "x86 x64 ARM"

call:BuildCRT 14.0.24210 "x86 x64 ARM"

call:BuildCRT 14.0.24225 "x86 x64 ARM"

call:BuildCRT 14.0.24231 "x86 x64 ARM"

call:BuildCRT 14.10.25017 "x86 x64 ARM ARM64"

call:BuildCRT 14.11.25503 "x86 x64 ARM ARM64"

call:BuildCRT 14.12.25827 "x86 x64 ARM ARM64"

call:BuildCRT 14.13.26128 "x86 x64 ARM ARM64"

call:BuildCRT 14.14.26428 "x86 x64 ARM ARM64"

call:BuildCRT 14.15.26726 "x86 x64 ARM ARM64"

call:BuildCRT 14.16.27023 "x86 x64 ARM ARM64"

call:BuildCRT 14.20.27508 "x86 x64 ARM ARM64"

call:BuildCRT 14.21.27702 "x86 x64 ARM ARM64"

call:BuildCRT 14.22.27905 "x86 x64 ARM ARM64"

::���ɶ�̬Spectre��
call:Build Dynamic_Spectre "x86 x64 ARM ARM64"

pause

goto:eof


::BuildCRT 14.0.24231 "x86 x64 ARM ARM64"
:BuildCRT

::����msvcrt.lib
call:Build Dynamic %2 "%1\Build\ltlbuild\ltlbuild.vcxproj"

::����msvcmrt.lib
call:Build Dynamic %2 "%1\Build\ltlbuild_CLR\ltlbuild_CLR.vcxproj"

::����vcruntime.lib
call:Build Redist  %2 "%1\Build\vcruntime\vcruntime.vcxproj"

::����msvcprt.lib
call:Build Redist  %2 "%1\Build\stl\stl.vcxproj"
call:Build Dynamic %2 "%1\Build\stl\stl.vcxproj"

::����concrt.lib
call:Build Redist  %2 "%1\Build\ConcRT\ConcRT.vcxproj"

goto:eof


::Build Dynamic "x86 x64 ARM ARM64" ["ucrt\ucrt.vcxproj"]
:Build

for %%i in (%~2)do call:BuildWithErrorCheck "%1" %%i %3

goto:eof

:BuildWithErrorCheck :: Dynamic|x86   ["ucrt\ucrt.vcxproj"]

if "%3"=="" ( msbuild "%~dp0VC-LTL.sln" /p:Configuration=%1 /p:Platform=%2 ) else ( msbuild "%~dp0VC-LTL.sln" /p:Configuration=%1 /p:Platform=%2 /t:%3 )

if %ERRORLEVEL% NEQ 0 echo %1 %2 �����������⣬����������&&pause

goto:eof
