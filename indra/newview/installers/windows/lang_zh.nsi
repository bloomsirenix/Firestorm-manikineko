; First is default
LoadLanguageFile "${NSISDIR}\Contrib\Language files\TradChinese.nlf"

; Language selection dialog
LangString InstallerLanguageTitle ${LANG_TRADCHINESE} "安裝語言"
LangString SelectInstallerLanguage ${LANG_TRADCHINESE} "請選擇安裝時使用的語言。"

; subtitle on license text caption
LangString LicenseSubTitleUpdate ${LANG_TRADCHINESE} "更新"
LangString LicenseSubTitleSetup ${LANG_TRADCHINESE} "設置"

LangString MULTIUSER_TEXT_INSTALLMODE_TITLE ${LANG_TRADCHINESE} "安裝模式"
LangString MULTIUSER_TEXT_INSTALLMODE_SUBTITLE ${LANG_TRADCHINESE} "爲所有使用者安裝（需要管理員權限）或僅爲當前使用者安裝？"
LangString MULTIUSER_INNERTEXT_INSTALLMODE_TOP ${LANG_TRADCHINESE} "使用管理員權限執行本安裝程式時，你可以選擇是否安裝到例如c:\Program Files或當前使用者的AppData\Local等資料夾。"
LangString MULTIUSER_INNERTEXT_INSTALLMODE_ALLUSERS ${LANG_TRADCHINESE} "爲所有使用者安裝"
LangString MULTIUSER_INNERTEXT_INSTALLMODE_CURRENTUSER ${LANG_TRADCHINESE} "僅爲當前使用者安裝"

; installation directory text
LangString DirectoryChooseTitle ${LANG_TRADCHINESE} "安裝目錄"
LangString DirectoryChooseUpdate ${LANG_TRADCHINESE} "請選擇 Manikineko Viewer 的安裝目錄，以便於將軟體更新成 ${VERSION_LONG} 版本（XXX）:"
LangString DirectoryChooseSetup ${LANG_TRADCHINESE} "請選擇安裝 Manikineko Viewer 的目錄："

LangString MUI_TEXT_DIRECTORY_TITLE ${LANG_TRADCHINESE} "安裝目錄"
LangString MUI_TEXT_DIRECTORY_SUBTITLE ${LANG_TRADCHINESE} "選擇要安裝Manikineko Viewer的目錄："

LangString MUI_TEXT_INSTALLING_TITLE ${LANG_TRADCHINESE} "正在安裝Manikineko Viewer…"
LangString MUI_TEXT_INSTALLING_SUBTITLE ${LANG_TRADCHINESE} "正在安裝Manikineko Viewer瀏覽器到$INSTDIR"

LangString MUI_TEXT_FINISH_TITLE ${LANG_TRADCHINESE} "正在安裝Manikineko Viewer…"
LangString MUI_TEXT_FINISH_SUBTITLE ${LANG_TRADCHINESE} "已安裝Manikineko Viewer瀏覽器到$INSTDIR"

LangString MUI_TEXT_ABORT_TITLE ${LANG_TRADCHINESE} "安裝過程中止"
LangString MUI_TEXT_ABORT_SUBTITLE ${LANG_TRADCHINESE} "將上安裝Manikineko Viewer瀏覽器到$INSTDIR。"

; CheckStartupParams message box
LangString CheckStartupParamsMB ${LANG_TRADCHINESE} "找上到'$INSTNAME'程序。自動更新失敗。"

; installation success dialog
LangString InstSuccesssQuestion ${LANG_TRADCHINESE} "現在要啟動 Manikineko Viewer 嗎？"

; remove old NSIS version
LangString RemoveOldNSISVersion ${LANG_TRADCHINESE} "檢查是否在使用舊版本…"

; check windows version
LangString CheckWindowsVersionDP ${LANG_TRADCHINESE} "檢查 Windows 版本…"
LangString CheckWindowsVersionMB ${LANG_TRADCHINESE} "Manikineko Viewer 只支援 Windows Vista SP2。"
LangString CheckWindowsServPackMB ${LANG_TRADCHINESE} "It is recomended to run Manikineko Viewer on the latest service pack for your operating system.$\nThis will help with performance and stability of the program."
LangString UseLatestServPackDP ${LANG_TRADCHINESE} "Please use Windows Update to install the latest Service Pack."

; checkifadministrator function (install)
LangString CheckAdministratorInstDP ${LANG_TRADCHINESE} "檢查安裝所需的權限..."
LangString CheckAdministratorInstMB ${LANG_TRADCHINESE} "您的帳戶似乎是「受限的帳戶《。$\n您必須有「管理員《權限才可以安裝 Manikineko Viewer。"
LangString CloseSecondLifeInstRM ${LANG_TRADCHINESE} "Manikineko Viewer failed to remove some files from a previous install."

; checkifadministrator function (uninstall)
LangString CheckAdministratorUnInstDP ${LANG_TRADCHINESE} "檢查卸載所需的權限..."
LangString CheckAdministratorUnInstMB ${LANG_TRADCHINESE} "您的帳戶似乎是「受限的帳戶《。$\n您必須有「管理員《權限才可以卸載 Manikineko Viewer。"

; checkcpuflags
LangString MissingSSE2 ${LANG_TRADCHINESE} "This machine may not have a CPU with SSE2 support, which is required to run Manikineko Viewer ${VERSION_LONG}. Do you want to continue?"

; closesecondlife function (install)
LangString CloseSecondLifeInstDP ${LANG_TRADCHINESE} "等待 Manikineko Viewer 停止運行…"
LangString CloseSecondLifeInstMB ${LANG_TRADCHINESE} "如果 Manikineko Viewer 仍在運行，將無法進行安裝。$\n$\n請結束您在 Manikineko Viewer 內的活動，然後選擇確定，將 Manikineko Viewer 關閉，以繼續安裝。$\n選擇「取消《，取消安裝。"

; closesecondlife function (uninstall)
LangString CloseSecondLifeUnInstDP ${LANG_TRADCHINESE} "等待 Manikineko Viewer 停止運行…"
LangString CloseSecondLifeUnInstMB ${LANG_TRADCHINESE} "如果 Manikineko Viewer 仍在運行，將無法進行卸載。$\n$\n請結束您在 Manikineko Viewer 內的活動，然後選擇確定，將 Manikineko Viewer 關閉，以繼續卸載。$\n選擇「取消《，取消卸載。"

; CheckNetworkConnection
LangString CheckNetworkConnectionDP ${LANG_TRADCHINESE} "正在檢查網路連接..."

; ask to remove user's data files
LangString RemoveDataFilesMB ${LANG_TRADCHINESE} "正在刪除 Documents and Settings 文件夾中的暫存文件？"

; delete program files
LangString DeleteProgramFilesMB ${LANG_TRADCHINESE} "在您的 Manikineko Viewer 程式目錄裡仍存有一些文件。$\n$\n這些文件可能是您新建或移動到 $\n$INSTDIR 文件夾中的。$\n $\n您還想要加以刪除嗎？"

; uninstall text
LangString UninstallTextMsg ${LANG_TRADCHINESE} "將從您的系統中卸載 Manikineko Viewer ${VERSION_LONG}。"

; ask to remove registry keys that still might be needed by other viewers that are installed
LangString DeleteRegistryKeysMB ${LANG_TRADCHINESE} "Do you want to remove application registry keys?$\n$\nIt is recomended to keep registry keys if you have other versions of Manikineko Viewer installed."

; <FS:Ansariel> Ask to create protocol handler registry entries
LangString CreateUrlRegistryEntries ${LANG_TRADCHINESE} "Do you want to register Manikineko Viewer as default handler for virtual world protocols?$\n$\nIf you have other versions of Manikineko Viewer installed, this will overwrite the existing registry keys."

; <FS:Ansariel> Optional start menu entry
LangString CreateStartMenuEntry ${LANG_TRADCHINESE} "Create an entry in the start menu?"

; <FS:Ansariel> Application name suffix for OpenSim variant
LangString ForOpenSimSuffix ${LANG_TRADCHINESE} "for OpenSimulator"

LangString DeleteDocumentAndSettingsDP ${LANG_TRADCHINESE} "Deleting files in Documents and Settings folder."
LangString UnChatlogsNoticeMB ${LANG_TRADCHINESE} "This uninstall will NOT delete your Manikineko Viewer chat logs and other private files. If you want to do that yourself, delete the Manikineko Viewer folder within your user Application data folder."
LangString UnRemovePasswordsDP ${LANG_TRADCHINESE} "Removing Manikineko Viewer saved passwords."

LangString MUI_TEXT_LICENSE_TITLE ${LANG_TRADCHINESE} "Vivox Voice System License Agreement"
LangString MUI_TEXT_LICENSE_SUBTITLE ${LANG_TRADCHINESE} "Additional license agreement for the Vivox Voice System components."
LangString MUI_INNERTEXT_LICENSE_TOP ${LANG_TRADCHINESE} "Please read the following license agreement carefully before proceeding with the installation:"
LangString MUI_INNERTEXT_LICENSE_BOTTOM ${LANG_TRADCHINESE} "You have to agree to the license terms to continue with the installation."
