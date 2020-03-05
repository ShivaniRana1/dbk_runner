all: main.c	
	gcc main.c -o main -framework OpenGL -lglut -Wdeprecated-declarations
	./main