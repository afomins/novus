# Microsoft Developer Studio Project File - Name="nov4" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=nov4 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "nov4.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "nov4.mak" CFG="nov4 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "nov4 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "nov4 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "nov4 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "nov4 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 dinput8.lib dxguid.lib opengl32.lib glu32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"nov4.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "nov4 - Win32 Release"
# Name "nov4 - Win32 Debug"
# Begin Group "dinput"

# PROP Default_Filter ""
# Begin Group "mouse"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\dinput\mouse\dinput_mouse.cpp
# End Source File
# Begin Source File

SOURCE=.\source\dinput\mouse\dinput_mouse_init.cpp
# End Source File
# End Group
# Begin Group "keyboard"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\dinput\keyboard\dinput_keyboard_init.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\source\dinput\dinput.cpp
# End Source File
# Begin Source File

SOURCE=.\source\dinput\dinput.h
# End Source File
# End Group
# Begin Group "draw"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\draw\draw2d.cpp
# End Source File
# Begin Source File

SOURCE=.\source\draw\draw2d.h
# End Source File
# End Group
# Begin Group "main"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\main\main.cpp
# End Source File
# Begin Source File

SOURCE=.\source\main\main.h
# End Source File
# Begin Source File

SOURCE=.\source\main\main_init.cpp
# End Source File
# End Group
# Begin Group "texture"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\texture\texture.cpp
# End Source File
# Begin Source File

SOURCE=.\source\texture\texture.h
# End Source File
# Begin Source File

SOURCE=.\source\texture\texture_init.cpp
# End Source File
# End Group
# Begin Group "timer"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\timer\timer.cpp
# End Source File
# Begin Source File

SOURCE=.\source\timer\timer.h
# End Source File
# End Group
# Begin Group "write"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\write\write.cpp
# End Source File
# Begin Source File

SOURCE=.\source\write\write.h
# End Source File
# Begin Source File

SOURCE=.\source\write\write_init.cpp
# End Source File
# End Group
# Begin Group "model"

# PROP Default_Filter ""
# Begin Group "create"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\model\create\model_create_border.cpp
# End Source File
# Begin Source File

SOURCE=.\source\model\create\model_create_plane.cpp
# End Source File
# Begin Source File

SOURCE=.\source\model\create\model_create_puck.cpp
# End Source File
# Begin Source File

SOURCE=.\source\model\create\model_create_skybox.cpp
# End Source File
# End Group
# Begin Group "line"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\model\line\model_line.cpp
# End Source File
# End Group
# Begin Group "vertex"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\model\vertex\model_vertex.cpp
# End Source File
# End Group
# Begin Group "triangle"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\model\triangle\model_triangle.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\source\model\model.cpp
# End Source File
# Begin Source File

SOURCE=.\source\model\model.h
# End Source File
# Begin Source File

SOURCE=.\source\model\model_init.cpp
# End Source File
# End Group
# Begin Group "camera"

# PROP Default_Filter ""
# Begin Group "script_rotate"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\camera\script_rotate\camera_script_rotate.cpp
# End Source File
# End Group
# Begin Group "script"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\camera\script\camera_script.cpp
# End Source File
# End Group
# Begin Group "rotate"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\camera\rotate\camera_rotate.cpp
# End Source File
# End Group
# Begin Group "freelook"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\camera\freelook\camera_freelook.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\source\camera\camera.cpp
# End Source File
# Begin Source File

SOURCE=.\source\camera\camera.h
# End Source File
# End Group
# Begin Group "interface"

# PROP Default_Filter ""
# Begin Group "cursor"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\interface\cursor\interface_cursor.cpp
# End Source File
# End Group
# Begin Group "button"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\interface\button\interface_button.cpp
# End Source File
# End Group
# Begin Group "rectangle"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\interface\rectange\interface_rectangle.cpp
# End Source File
# End Group
# Begin Group "scroll_bar"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\interface\scroll_bar\interface_scroll_bar.cpp
# End Source File
# End Group
# Begin Group "window"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\interface\window\interface_window.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\source\interface\interface.cpp
# End Source File
# Begin Source File

SOURCE=.\source\interface\interface.h
# End Source File
# End Group
# Begin Group "game"

# PROP Default_Filter ""
# Begin Group "player"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\game\player\game_player.cpp
# End Source File
# End Group
# Begin Group "game_model"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\game\model\game_model_create.cpp
# End Source File
# Begin Source File

SOURCE=.\source\game\model\game_model_draw.cpp
# End Source File
# End Group
# Begin Group "game_camera"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\game\camera\game_camera.cpp
# End Source File
# Begin Source File

SOURCE=.\source\game\camera\game_camera_freelook.cpp
# End Source File
# Begin Source File

SOURCE=.\source\game\camera\game_camera_init.cpp
# End Source File
# Begin Source File

SOURCE=.\source\game\camera\game_camera_rotate.cpp
# End Source File
# Begin Source File

SOURCE=.\source\game\camera\game_camera_script.cpp
# End Source File
# End Group
# Begin Group "game_dinput"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\game\dinput\game_dinput.cpp
# End Source File
# Begin Source File

SOURCE=.\source\game\dinput\game_dinput_keyboard.cpp
# End Source File
# Begin Source File

SOURCE=.\source\game\dinput\game_dinput_mouse.cpp
# End Source File
# End Group
# Begin Group "game_interface"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\game\interface\game_interface_button_process.cpp
# End Source File
# Begin Source File

SOURCE=.\source\game\interface\game_interface_init.cpp
# End Source File
# End Group
# Begin Group "phiziks"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\game\phiziks\game_phiziks.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\source\game\game.cpp
# End Source File
# Begin Source File

SOURCE=.\source\game\game.h
# End Source File
# Begin Source File

SOURCE=.\source\game\game_init.cpp
# End Source File
# End Group
# End Target
# End Project
