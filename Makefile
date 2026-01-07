# Makefile : build exécutable Windows
w-exe: winemenumgr.c
	x86_64-w64-mingw32-gcc -o winemenumgr.exe winemenumgr.c
