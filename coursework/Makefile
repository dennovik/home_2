CC=C:\TDM-GCC-64\bin\gcc.exe
CFLAGS=-c -W -Wall -O3 
#CFLAGS=-c -W -Wall -g3 
LFLAGS=-lm

all: report.exe

report.exe: report.o temp_functions.o
	$(CC) $(LFLAGS) -o report.exe report.o temp_functions.o

report.o: report.c temp_functions.h
	$(CC) $(CFLAGS) report.c

temp_functions.o: temp_functions.c temp_functions.h
	$(CC) $(CFLAGS) temp_functions.c

.PHONY: all

