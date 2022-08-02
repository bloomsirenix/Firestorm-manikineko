; First is default
LoadLanguageFile "${NSISDIR}\Contrib\Language files\PortugueseBR.nlf"

; Language selection dialog
LangString InstallerLanguageTitle  ${LANG_PORTUGUESEBR} "Instalador Linguagem"
LangString SelectInstallerLanguage  ${LANG_PORTUGUESEBR} "Por favor seleccione a linguagem do instalador"

; subtitle on license text caption
LangString LicenseSubTitleUpdate ${LANG_PORTUGUESEBR} " Atualizar"
LangString LicenseSubTitleSetup ${LANG_PORTUGUESEBR} " Instalar"

LangString MULTIUSER_TEXT_INSTALLMODE_TITLE ${LANG_PORTUGUESEBR} "Modo de Instalação"
LangString MULTIUSER_TEXT_INSTALLMODE_SUBTITLE ${LANG_PORTUGUESEBR} "Instalar para todos os usuários (necessário Administrador) ou somente para o usuário atual?"
LangString MULTIUSER_INNERTEXT_INSTALLMODE_TOP ${LANG_PORTUGUESEBR} "Quando operar este instalador com os privilégios de Administrador, você pode escolher instalar em (ex.) c:\Program Files ou na pasta local do usuário AppData\Local."
LangString MULTIUSER_INNERTEXT_INSTALLMODE_ALLUSERS ${LANG_PORTUGUESEBR} "Instalar para todos os usuários"
LangString MULTIUSER_INNERTEXT_INSTALLMODE_CURRENTUSER ${LANG_PORTUGUESEBR} "Instalar somente para o usuário atual"

; installation directory text
LangString DirectoryChooseTitle ${LANG_PORTUGUESEBR} "Diretório de Instalação" 
LangString DirectoryChooseUpdate ${LANG_PORTUGUESEBR} "Selecione o diretório do Manikineko Viewer para atualizar para a versão ${VERSION_LONG}.(XXX):"
LangString DirectoryChooseSetup ${LANG_PORTUGUESEBR} "Selecione o diretório para a instalação do Manikineko Viewer em:"

LangString MUI_TEXT_DIRECTORY_TITLE ${LANG_PORTUGUESEBR} "Diretório de Instalação"
LangString MUI_TEXT_DIRECTORY_SUBTITLE ${LANG_PORTUGUESEBR} "Selecione o diretório ao qual deseja instalar o Manikineko Viewer:"

LangString MUI_TEXT_INSTALLING_TITLE ${LANG_PORTUGUESEBR} "Instalando o Manikineko Viewer..."
LangString MUI_TEXT_INSTALLING_SUBTITLE ${LANG_PORTUGUESEBR} "Instalando o visualizador Manikineko Viewer para $INSTDIR"

LangString MUI_TEXT_FINISH_TITLE ${LANG_PORTUGUESEBR} "Instalando o Manikineko Viewer"
LangString MUI_TEXT_FINISH_SUBTITLE ${LANG_PORTUGUESEBR} "Visualizador Manikineko Viewer instalado para $INSTDIR."

LangString MUI_TEXT_ABORT_TITLE ${LANG_PORTUGUESEBR} "Instalação Anulada"
LangString MUI_TEXT_ABORT_SUBTITLE ${LANG_PORTUGUESEBR} "Visualizador Manikineko Viewer não instalado para $INSTDIR."

; CheckStartupParams message box
LangString CheckStartupParamsMB ${LANG_PORTUGUESEBR} "Não é possível encontrar o programa '$INSTNAME'. Ocorreu uma falha na atualização silenciosa."

; installation success dialog
LangString InstSuccesssQuestion ${LANG_PORTUGUESEBR} "Iniciar o Manikineko Viewer agora?"

; remove old NSIS version
LangString RemoveOldNSISVersion ${LANG_PORTUGUESEBR} "Verificando a versão anterior..."

; check windows version
LangString CheckWindowsVersionDP ${LANG_PORTUGUESEBR} "Verificando a versão do Windows..."
LangString CheckWindowsVersionMB ${LANG_PORTUGUESEBR} 'O Manikineko Viewer suporta apenas Windows Vista SB2.'
LangString CheckWindowsServPackMB ${LANG_PORTUGUESEBR} "It is recomended to run Manikineko Viewer on the latest service pack for your operating system.$\nThis will help with performance and stability of the program."
LangString UseLatestServPackDP ${LANG_PORTUGUESEBR} "Please use Windows Update to install the latest Service Pack."

; checkifadministrator function (install)
LangString CheckAdministratorInstDP ${LANG_PORTUGUESEBR} "Verificando a permissão para instalação..."
LangString CheckAdministratorInstMB ${LANG_PORTUGUESEBR} 'Você parece estar usando uma conta "limitada".$\nVocê deve ser um "administrador" para poder instalar o Manikineko Viewer.'

; checkifadministrator function (uninstall)
LangString CheckAdministratorUnInstDP ${LANG_PORTUGUESEBR} "Verificando a permissão para desinstalação..."
LangString CheckAdministratorUnInstMB ${LANG_PORTUGUESEBR} 'Você parece estar usando uma conta "limitada".$\nVocê deve ser um "administrador" para poder desinstalar o Manikineko Viewer.'

; checkcpuflags
LangString MissingSSE2 ${LANG_PORTUGUESEBR} "This machine may not have a CPU with SSE2 support, which is required to run Manikineko Viewer ${VERSION_LONG}. Do you want to continue?"

; closesecondlife function (install)
LangString CloseSecondLifeInstDP ${LANG_PORTUGUESEBR} "Esperando o encerramento do Manikineko Viewer..."
LangString CloseSecondLifeInstMB ${LANG_PORTUGUESEBR} "O Manikineko Viewer não pode ser instalado enquanto ainda está sendo executado.$\n$\nTermine o que estava fazendo e selecione OK para fechar o Manikineko Viewer e continuar.$\nSelecione CANCELAR para cancelar a instalação."
LangString CloseSecondLifeInstRM ${LANG_PORTUGUESEBR} "Manikineko Viewer failed to remove some files from a previous install."

; closesecondlife function (uninstall)
LangString CloseSecondLifeUnInstDP ${LANG_PORTUGUESEBR} "Esperando o encerramento do Manikineko Viewer..."
LangString CloseSecondLifeUnInstMB ${LANG_PORTUGUESEBR} "O Manikineko Viewer não pode ser desinstalado enquanto ainda está sendo executado.$\n$\nTermine o que estava fazendo e selecione OK para fechar o Manikineko Viewer e continuar.$\nSelecione CANCELAR para cancelar."

; CheckNetworkConnection
LangString CheckNetworkConnectionDP ${LANG_PORTUGUESEBR} "Verificando a conexão de rede..."

; ask to remove user's data files
LangString RemoveDataFilesMB ${LANG_PORTUGUESEBR} "Excluindo arquivos de cache na pasta Documents and Settings?"

; delete program files
LangString DeleteProgramFilesMB ${LANG_PORTUGUESEBR} "Ainda existem arquivos em seu diretório do programa Manikineko Viewer.$\n$\nProvavelmente são arquivos que você criou ou moveu para:$\n$INSTDIR$\n$\nDeseja removê-los?"

; uninstall text
LangString UninstallTextMsg ${LANG_PORTUGUESEBR} "Isso desinstalará o Manikineko Viewer ${VERSION_LONG} do seu sistema."

; ask to remove registry keys that still might be needed by other viewers that are installed
LangString DeleteRegistryKeysMB ${LANG_PORTUGUESEBR} "Do you want to remove application registry keys?$\n$\nIt is recomended to keep registry keys if you have other versions of Manikineko Viewer installed."

; <FS:Ansariel> Ask to create protocol handler registry entries
LangString CreateUrlRegistryEntries ${LANG_PORTUGUESEBR} "Do you want to register Manikineko Viewer as default handler for virtual world protocols?$\n$\nIf you have other versions of Manikineko Viewer installed, this will overwrite the existing registry keys."

; <FS:Ansariel> Optional start menu entry
LangString CreateStartMenuEntry ${LANG_PORTUGUESEBR} "Create an entry in the start menu?"

; <FS:Ansariel> Application name suffix for OpenSim variant
LangString ForOpenSimSuffix ${LANG_PORTUGUESEBR} "for OpenSimulator"

LangString DeleteDocumentAndSettingsDP ${LANG_PORTUGUESEBR} "Deleting files in Documents and Settings folder."
LangString UnChatlogsNoticeMB ${LANG_PORTUGUESEBR} "This uninstall will NOT delete your Manikineko Viewer chat logs and other private files. If you want to do that yourself, delete the Manikineko Viewer folder within your user Application data folder."
LangString UnRemovePasswordsDP ${LANG_PORTUGUESEBR} "Removing Manikineko Viewer saved passwords."

LangString MUI_TEXT_LICENSE_TITLE ${LANG_PORTUGUESEBR} "Vivox Voice System License Agreement"
LangString MUI_TEXT_LICENSE_SUBTITLE ${LANG_PORTUGUESEBR} "Additional license agreement for the Vivox Voice System components."
LangString MUI_INNERTEXT_LICENSE_TOP ${LANG_PORTUGUESEBR} "Please read the following license agreement carefully before proceeding with the installation:"
LangString MUI_INNERTEXT_LICENSE_BOTTOM ${LANG_PORTUGUESEBR} "You have to agree to the license terms to continue with the installation."
