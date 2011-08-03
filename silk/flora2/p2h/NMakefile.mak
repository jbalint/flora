# Make file for prolog2hilog.dll


!IF EXISTS (..\.prolog_path_wind) 
!INCLUDE ..\.prolog_path_wind
!ENDIF

CPP = cl.exe
LINK32 = link.exe

OUTDIR     = windows
ARCHDIR    = "$(PROLOGDIR)\config\x86-pc-windows"
ARCHBINDIR = $(ARCHDIR)\bin
ARCHOBJDIR = $(ARCHDIR)\saved.o

ALL :: "$(OUTDIR)\prolog2hilog.dll"  "$(OUTDIR)\flora_ground.dll"

CLEAN :
	-@if exist *.obj" erase *.obj"
	-@if exist *.dll" erase *.dll"
	-@if exist *.exp" erase *.exp"
	-@if exist *~ erase *~
	-@if exist .#* erase .#*
	-@if exist *.bak erase *.bak


CPP_PROJ = /nologo /MT /W3 /EHsc /O2 /I "$(ARCHDIR)" \
	 /I "$(PROLOGDIR)\emu" /I "$(PROLOGDIR)\prolog_includes" \
	 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" \
	 /Fo"$(ARCHOBJDIR)\\" /Fd"$(ARCHOBJDIR)\\" /c 
	

"$(ARCHOBJDIR)\prolog2hilog.obj" :: prolog2hilog.c
	$(CPP) $(CPP_PROJ) prolog2hilog.c

"$(ARCHOBJDIR)\flora_ground.obj" :: flora_ground.c
	$(CPP) $(CPP_PROJ) flora_ground.c

LINK_FLAGS_P2H = kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib \
	 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib \
	 odbc32.lib odbccp32.lib xsb.lib \
	 /nologo /dll \
	 /machine:I386 /out:"$(OUTDIR)\prolog2hilog.dll" \
	 /libpath:"$(ARCHBINDIR)"

LINK_FLAGS_GRND = kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib \
	 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib \
	 odbc32.lib odbccp32.lib xsb.lib \
	 /nologo /dll \
	 /machine:I386 /out:"$(OUTDIR)\flora_ground.dll" \
	 /libpath:"$(ARCHBINDIR)"

LINK_OBJS_P2H  =  "$(ARCHOBJDIR)\prolog2hilog.obj"
LINK_OBJS_GRND =  "$(ARCHOBJDIR)\flora_ground.obj"

"$(OUTDIR)\prolog2hilog.dll" :: $(LINK_OBJS_P2H)
    $(LINK32) @<<
  $(LINK_FLAGS_P2H) $(LINK_OBJS_P2H)
<<

"$(OUTDIR)\flora_ground.dll" :: $(LINK_OBJS_GRND)
    $(LINK32) @<<
  $(LINK_FLAGS_GRND) $(LINK_OBJS_GRND)
<<
