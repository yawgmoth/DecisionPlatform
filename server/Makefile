

all:
	f77 -c processing/*.f
	g++ -g *.o *.cpp *.c framework/*.c -I framework -I ../common -o server.exe 