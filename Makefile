CC = g++

all:
	$(CC) *.cpp -framework GLUT -framework Cocoa -framework OpenGL -I. -o cgprog

clean:
	rm cgprog

