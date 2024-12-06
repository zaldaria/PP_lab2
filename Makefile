CC = g++
CFLAGS = -Wall -g
EXECUTABLE = comp
INSTALL_DIR = ~/pp_lab 

all: $(EXECUTABLE)

$(EXECUTABLE): PP_lab2.cpp ThreadsPool.cpp ThreadsPool.h
	$(CC) $(CFLAGS) PP_lab2.cpp ThreadsPool.cpp -o $(EXECUTABLE)

install: $(EXECUTABLE)
	mkdir -p $(INSTALL_DIR)
	cp $(EXECUTABLE) $(INSTALL_DIR)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all install clean
