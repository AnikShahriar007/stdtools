stdtools.o: stdtools.c stdtools.h
	gcc -c -fPIC stdtools.c -o stdtools.o
libstdtools.so: stdtools.o
	gcc -shared stdtools.o -o libstdtools.so
libstdtools.a: stdtools.o libstdtools.so # Added additional 'libstdtools.so', otherwise make will ignore libstdtools.so creation.
	ar -rcs libstdtools.a stdtools.o

