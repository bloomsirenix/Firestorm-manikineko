@echo off
echo "Configure"
set AUTOBUILD_CONFIG_FILE=my_autobuild.xml
autobuild configure -A 64 -c ReleaseFS_open -- --chan ManikinekoOnline -DLL_TESTS:BOOL=FALSE

echo "Build"
autobuild build -A 64 -c ReleaseFS_open --no-configure