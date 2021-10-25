set AUTOBUILD_VSVER=150
set AUTOBUILD_CONFIG_FILE=my_autobuild.xml

autobuild configure -A 64 -c ReleaseFS_open -- --package --chan manikineko_metaverse -DLL_TESTS:BOOL=FALSE
echo "build using: autobuild build -A 64 -c ReleaseFS_open --no-configure"