@echo off
echo "Configure"
autobuild configure -A 64 -c ReleaseFS_open -- --chan ManikinekoOnline -DLL_TESTS:BOOL=FALSE -- --fmodstudio --package

echo "Build"
autobuild build -A 64 -c ReleaseFS_open --no-configure
