set AUTOBUILD_VSVER=150
set AUTOBUILD_CONFIG_FILE=my_autobuild.xml
set AUTOBUILD_VARIABLES_FILE=my_autobuild.xml
autobuild configure -c ReleaseFS_open -- --fmodstudio --package --chan Manikineko -DLL_TESTS:BOOL=FALSE
autobuild configure -A 64 -c ReleaseFS_open -- --chan Manikineko -DLL_TESTS:BOOL=FALSE