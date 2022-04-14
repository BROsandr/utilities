system_include = [r'C:\Code\c++\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\include', r'C:\programs\lemon\include']
libpath=[r'C:\programs\lemon\lib', r'C:\Code\c++\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\lib'] 
libs = ['sfml-graphics-d', 'sfml-system-d', 'sfml-window-d', 'lemon']
tools = ['clang++', 'mslink']
ccflags = ['-D_DLL']
# ccflags = ['/NODEFAULTLIB:linrary']
# linkflags = ['-nostartfiles']
linkflags = []
env = Environment(CPPPATH=system_include, LIBPATH = libpath, LIBS=libs, LINKFLAGS = linkflags, CCFLAGS = ccflags, LINK = 'lld-link', tools = tools)
env.Tool('compilation_db')
env.CompilationDatabase()
env.Program('open-yorg', 'Source1.cpp')
