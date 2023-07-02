echo off

set BUILD_COMMAND=%CD%\..\tools\util\make\make.exe -f %CD%\..\Make\make_000.gmk TYP_OS=win %1%

echo Build command is: %BUILD_COMMAND%

%BUILD_COMMAND%
