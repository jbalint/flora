; Script generated by the Inno Setup Script Wizard.
; Modified from xsb.iss and flora2.iss
; Double click on this file to run with inno, then build-menu, compile.
; A compiled version of Flora-2 must exist at the location pointed
; by the FlrBaseDir variable below.
; A compiled version of XSB must exist at the location of XSBBaseDir

#define MyAppName "Flora-2"
#define FlrVersion "0.99.3"
#define XSBVersion "3.4"
#define MyAppVerName "Flora-2  v. "+FlrVersion+" (Aronia) and XSB "+XSBVersion
#define MyAppPublisher "Flora-2"
#define MyAppURL "http://flora.sourceforge.net/"
#define MyAppUrlName "Flora-2 Web Site.url"
#define FlrLicenseURL "http://www.apache.org/licenses/LICENSE-2.0"
#define FlrLicenseUrlName "Apache License Web Site.url"
#define XSBLicenseURL "http://www.gnu.org/licenses/old-licenses/lgpl-2.0.html"
#define XSBLicenseUrlName "LGPL 2.0 License Web Site.url"

#define FLORA_DIR "{reg:HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment,FLORA_DIR|{pf}\Flora-2}"
#define FlrBaseDir "H:\FLORA\bundle\flora2"
#define XSBBaseDir "H:\FLORA\bundle\XSB"

#define flrapp "{app}\flora2"
#define xsbapp "{app}\XSB"

[Setup]
AppName={#MyAppName}
AppVerName={#MyAppVerName}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
ChangesEnvironment=yes
DefaultDirName={#FLORA_DIR}
DefaultGroupName={#MyAppName}
DisableProgramGroupPage=yes
LicenseFile={#FlrBaseDir}\LICENSE_bundle
InfoBeforeFile={#FlrBaseDir}\admin\windows\InstallMessage
OutputBaseFilename=flora2-{#FlrVersion}
Compression=lzma
SolidCompression=yes
PrivilegesRequired=none

VersionInfoVersion={#FlrVersion}
VersionInfoCopyright=� The Research Foundation of SUNY, 1986 - 2013

AllowRootDirectory=yes
UninstallFilesDir="{userdocs}\Flora-2 uninstaller"

MinVersion=0,5.1

; "ArchitecturesInstallIn64BitMode=x64" requests that the install be
; done in "64-bit mode" on x64, meaning it should use the native
; 64-bit Program Files directory and the 64-bit view of the registry.
; On all other architectures it will install in "32-bit mode".
ArchitecturesInstallIn64BitMode=x64
; Note: We don't set ProcessorsAllowed because we want this
; installation to run on all architectures (including Itanium,
; since it's capable of running 32-bit code too).

[Types]
Name: "full"; Description: "Full Flora-2 and XSB installation (recommended)"
Name: "base"; Description: "Base Flora-2 and XSB installation"

[Components]
Name: "base"; Description: "Base system"; Types: full base; Flags: disablenouninstallwarning
Name: "base\sources"; Description: "Base system plus the source files"; Types: full base; Flags: disablenouninstallwarning
Name: "documentation"; Description: "Documentation"; Types: full; Flags: disablenouninstallwarning

[Tasks]
Name: website; Description: "&Visit {#MyAppName} web site"; Components: base
Name: shortcut; Description: "&Create a desktop shortcut to run Flora-2"; Components: base

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Messages]
BeveledLabel=Flora-2 {#FlrVersion} � The Research Foundation of SUNY, 1986 - 2013

[Dirs]
Name: "{app}" ; Permissions: users-modify users-full
Name: "{userdocs}\Flora-2 uninstaller"

[Files]
Source: "{#FlrBaseDir}\*.xwam"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\*.flh"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\floraconfig.bat"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\runflora.bat"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\LICENSE_bundle"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\etc\flora.ico"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\etc"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\*.P"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\*.H"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\makeflora.bat"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\AT\*.flr"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\AT"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\AT\include\*.flh"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\AT\include"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\AT\prolog\*.P"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\AT\prolog"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\AT\prolog\*.xwam"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\AT\prolog"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\AT\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\AT"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\closure\*.flh"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\closure"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\closure\*.fli"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\closure"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\closure\*.inc"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\closure"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\closure\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\closure"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\datatypes\*.xwam"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\datatypes"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\datatypes\*.P"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\datatypes"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\datatypes\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\datatypes"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\debugger\*.xwam"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\debugger"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\debugger\*.dat"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\debugger"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\debugger\*.P"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\debugger"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\debugger\*.in"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\debugger"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\debugger\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\debugger"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\demos\*.flr"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\demos"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\demos\sgml\*.flr"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\demos\sgml"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\demos\xpath\*.flr"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\demos\xpath"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\demos\sgml\expectedoutput"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\demos\expectedoutput"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\demos\xpath\expectedoutput"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\xpath\expectedoutput"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\demos\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\demos"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\docs\*.pdf"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\docs"; Components: documentation; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\docs\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\docs"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\emacs\*.el"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\emacs"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\emacs\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\emacs"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\emacs\README"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\emacs"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\flrincludes\*.flh"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\flrincludes"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\genincludes\*.flh"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\genincludes"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\genincludes\*.fli"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\genincludes"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\genincludes\*.inc"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\genincludes"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\genincludes\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\genincludes"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\headerinc\*.flh"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\headerinc"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\includes\*.flh"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\includes"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\includes\*.fli"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\includes"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\includes\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\includes"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\lib\*.flr"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\lib"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\lib\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\lib"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\lib\include\*.flh"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\lib"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\libinc\*.flh"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\libinc"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs


Source: "{#FlrBaseDir}\cc\*.P"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\cc"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\cc\prolog2hilog.*"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\cc"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\cc\flora_ground.*"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\cc"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\cc\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\cc"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\cc\NMakefile64.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\cc"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\cc\windows\*.dll"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\cc\windows"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\cc\windows\*.exp"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\cc\windows"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\cc\windows\*.lib"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\cc\windows"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\cc\windows64\*.dll"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\cc\windows64"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\cc\windows64\*.exp"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\cc\windows64"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\cc\windows64\*.lib"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\cc\windows64"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\pkgs\*.flr"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\pkgs"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\pkgs\include\*.flh"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\pkgs\include"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\pkgs\prolog\*.P"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\pkgs\prolog"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\pkgs\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\pkgs"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\syslib\*.xwam"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\syslib"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\syslib\*.P"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\syslib"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\syslib\*.H"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\syslib"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#FlrBaseDir}\syslib\NMakefile.mak"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\syslib"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\syslibinc\*.flh"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\syslibinc"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#FlrBaseDir}\java"; Excludes: ".*,CVS"; DestDir: "{#flrapp}\java"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

;; XSB files
Source: "{#XSBBaseDir}\README"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\LICENSE"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#XSBBaseDir}\bin\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\bin"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\config\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\config"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\pthreads\Pre-built\lib\pthreadVSE1.dll"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\config\i686-pc-cygwin-mt\bin"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#XSBBaseDir}\syslib\*.xwam"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\syslib"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\cmplib\*.xwam"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\cmplib"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\lib\*.xwam"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\lib"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\prolog-commons\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\prolog-commons"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\prolog_includes\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\prolog_includes"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\emu\*.h"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\emu"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\emu\debugs\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\emu\debugs"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\emu\orastuff\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\emu\orastuff"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#XSBBaseDir}\syslib\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\syslib"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\cmplib\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\cmplib"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\lib\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\lib"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\prolog-commons\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\prolog-commons"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\prolog_includes\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\prolog_includes"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\emu\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\emu"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\etc\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\etc"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\gpp\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\gpp"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "{#XSBBaseDir}\docs\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\docs"; Components: documentation; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\examples\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\examples"; Components: base\sources; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#XSBBaseDir}\packages\*"; Excludes: ".*,CVS"; DestDir: "{#xsbapp}\packages"; Components: base; Flags: ignoreversion recursesubdirs createallsubdirs

[INI]
Filename: "{app}\{#MyAppUrlName}"; Section: "InternetShortcut"; Key: "URL"; String: "{#MyAppURL}"; Components: base
Filename: "{app}\{#FlrLicenseUrlName}"; Section: "InternetShortcut"; Key: "URL"; String: "{#FlrLicenseURL}"; Components: base
Filename: "{app}\{#XSBLicenseUrlName}"; Section: "InternetShortcut"; Key: "URL"; String: "{#XSBLicenseURL}"; Components: base


[Icons]
Name: "{group}\Flora-2"; Filename: "cmd" ; Parameters: "/k ""cd {#flrapp} & runflora.bat"""; Comment: "Runs Flora-2 within a Windows command window"; WorkingDir: "{#flrapp}"; Components: base; IconFilename: "{#flrapp}\etc\flora.ico"

Name: "{userdesktop}\Flora-2"; Filename: "cmd" ; Parameters: "/k ""cd {#flrapp} & runflora.bat"""; Comment: "Runs Flora-2 within a Windows command window"; WorkingDir: "{#flrapp}"; Components: base; IconFilename: "{#flrapp}\etc\flora.ico"; Tasks: shortcut

Name: "{group}\Flora-2 License"; Filename: "{#FlrLicenseURL}"; Components: base
Name: "{group}\XSB License"; Filename: "{#XSBLicenseURL}"; Components: base

Name: "{group}\Web Site"; Filename: "{#MyAppURL}"; Components: base

Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"; Components: base

[Registry]
Root: HKLM; Subkey: "SYSTEM\CurrentControlSet\Control\Session Manager\Environment"; ValueType: expandsz; ValueName: "FLORA_DIR"; ValueData: "{app}"; Components: base; Flags: deletevalue uninsdeletevalue

[Run]
; If we are on x64, will use xsb64.bat
Filename: "cmd" ; Parameters: "/c """"{#flrapp}\floraconfig.bat"" ""{#xsbapp}\bin\xsb64"""""; WorkingDir: "{#flrapp}"; Check: Is64BitInstallMode
; Otherwise, will use xsb.bat
Filename: "cmd" ; Parameters: "/c """"{#flrapp}\floraconfig.bat"" ""{#xsbapp}\bin\xsb"""""; WorkingDir: "{#flrapp}"; Check: not Is64BitInstallMode

Filename: "{app}\{#MyAppUrlName}"; Flags: shellexec nowait; Tasks: website

[UninstallDelete]
Type: filesandordirs; Name: "{app}"; Components: base
Type: filesandordirs; Name: "{group}"; Components: base
