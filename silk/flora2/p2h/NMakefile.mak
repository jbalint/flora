# Make file for prolog2hilog.dll


!IF EXISTS (..\.prolog_path_wind) 
!INCLUDE ..\.prolog_path_wind
!ENDIF

CPP = cl.exe
LINK32 = link.exe

OUTDIR = windows
INTDIR = .

ALL : "$(OUTDIR)\prolog2hilog.dll"  "$(OUTDIR)\flora_ground.dll"

CLEAN :
	-@erase "$(INTDIR)\prolog2hilog.obj"
	-@erase "$(INTDIR)\prolog2hilog.dll"
	-@erase "$(INTDIR)\prolog2hilog.exp"
	-@erase "$(INTDIR)\flora_ground.obj"
	-@erase "$(INTDIR)\flora_ground.dll"
	-@erase "$(INTDIR)\flora_ground.exp"
	-@erase *~
	-@erase .#*
	-@erase *.bak


CPP_PROJ = /nologo /MT /W3 /EHsc /O2 /I "$(PROLOGDIR)\config\x86-pc-windows" \
		 /I "$(PROLOGDIR)\emu" /I "$(PROLOGDIR)\prolog_includes" \
		 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" \
		 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /c 
	

"$(INTDIR)\prolog2hilog.obj" : prolog2hilog.c "$(INTDIR)"
	$(CPP) $(CPP_PROJ) prolog2hilog.c

"$(INTDIR)\flora_ground.obj" : flora_ground.c "$(INTDIR)"
	$(CPP) $(CPP_PROJ) flora_ground.c

LINK_FLAGS_P2H = kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib \
		 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib \
		 odbc32.lib odbccp32.lib xsb.lib /nologo /dll \
		 /machine:I386 /out:"$(OUTDIR)\prolog2hilog.dll" \
		 /libpath:"$(PROLOGDIR)\config\x86-pc-windows\bin" 

LINK_FLAGS_GRND = kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib \
		  advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib \
		  odbc32.lib odbccp32.lib xsb.lib /nologo /dll \
		  /machine:I386 /out:"$(OUTDIR)\flora_ground.dll" \
		  /libpath:"$(PROLOGDIR)\config\x86-pc-windows\bin" 

LINK_OBJS_P2H  =  "$(INTDIR)\prolog2hilog.obj"
LINK_OBJS_GRND =  "$(INTDIR)\flora_ground.obj"

"$(OUTDIR)\prolog2hilog.dll" : "$(OUTDIR)" $(LINK_OBJS_P2H)
    $(LINK32) @<<
  $(LINK_FLAGS_P2H) $(LINK_OBJS_P2H)
<<

"$(OUTDIR)\flora_ground.dll" : "$(OUTDIR)" $(LINK_OBJS_GRND)
    $(LINK32) @<<
  $(LINK_FLAGS_GRND) $(LINK_OBJS_GRND)
<<
