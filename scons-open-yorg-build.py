system_include = [r'C:\Code\c++\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\include', r'C:\programs\lemon\include']
libpath=[r'C:\programs\lemon\lib', r'C:\Code\c++\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\lib'] 
libs = ['sfml-graphics', 'sfml-system', 'sfml-window', 'lemon']
user_include =[  '../include']
# tools = ['clang++', 'lld-link']
ccflags = ['/Zi', '/Ob0', '/Od', '/RTC1', '-MD']
# ccflags = []
linkflags = ['-nostartfiles']
# linkflags = []
env = Environment(CPPPATH=system_include + user_include, LIBPATH = libpath, LIBS=libs, CCFLAGS = ccflags)
sources = Glob('**/*.cpp') + Glob('*.cpp')
env.Program('open-yorg', sources)
