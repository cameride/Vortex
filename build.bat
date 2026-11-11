@echo off
echo Building Advanced External Game Client...

:: Create build directory
if not exist "build" mkdir "build"
cd build

echo Compiling with cl (Visual Studio compiler)
cl ..\*.cpp /EHsc /Fe:ExternalGameClient.exe /link user32.lib kernel32.lib d3d11.lib dxgi.lib lua54.lib

if %ERRORLEVEL% equ 0 (
    echo.
echo Build successful! 
echo Executable created: ExternalGameClient.exe
) else (
    echo.
echo Build failed with error code %ERRORLEVEL%
)
pause