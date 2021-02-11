.PHONY: all clean install uninstall

all: linEq 

clean:		
				rm -rf linEq *.o
		
linEq:		 main.c 
				gcc -o linEq main.c 

install:	 
				install ./linEq /usr/local/bin

uninstall:	
				rm -rf /usr/local/bin/linEq