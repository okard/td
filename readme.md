td - An open source tower defense game.
=========================================


Libraries used
--------------------
- [OpenGL](http://www.opengl.org/)
- [Horde3D](http://www.horde3d.org/)
- [glul](http://github.com/okard/glul)
- [cul](http://github.com/okard/cul)
- [LuaJIT 2](http://luajit.org/)


TODO
--------------------
- Switch from OGRE to Horde3D
- Use CUL and GLUL library
- Rewrite engine
- Start implementing editor with QT4 


Build td under Windows (OLD)
--------------------------

Software required:
- GIT [1.7.0.2]                 http://code.google.com/p/msysgit/downloads/list
- CMAKE [2.8.1]                 http://www.cmake.org/cmake/resources/software.html
- TDM MinGW [4.4.1-2]           http://www.tdragon.net/recentgcc/
- OgreSDK MinGW [1.7.1]         http://www.ogre3d.org/download/sdk
- LuaJIT [2.0.0-beta4]          http://luajit.org/download.html
        
Current used build environment:
        root_folder/
                cmake/                  (cmake extracted)
                luajit2/                (luajit extracted)
                mingw/                  (mingw extracted core, binutils, gdb, make, g++, mingwrt-dev, mingwrt-dll, w32api)
                ogre_sdk/               (ogre sdk extracted)
                td_src/                 (git checkout of td source code)
                
        NOTE: git is installed normally, also possible with mingw and cmake, 
                ogre and lujit folders are used in CMake file of td so this structure is required for these two
                
        1. Add MinGW bin and CMake bin to PATH environment variable
        2. LuaJIT isn't prebuild so go to luajit2 folder
                # mingw32-make
                (check if lua51.dll exist in src folder after build)
        3. With the folder structure described above go to td_src
        
        4. OPTIONAL:    Add Ogre bin folders and LuaJIT src folder to PATH for required dlls
        ALTERNATIV:     Add required dlls to td_src folder (At the moment: lua51.dll, OgreMain.dll, OIS.dll, RenderSystem_GL.dll)
        
        5. Go into td_src
                (create build folder if not exist)
                # built.bat
                
        6. execute with
                # build\td.exe
        
        
                
                
