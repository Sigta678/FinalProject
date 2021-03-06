all: clean main run

S_PATH = ./src/
SRC = -L ./src                                                                                                                                                                                                                                                                                       
INC = -I ./include
CFLAG = -g -Wall

main: controller.o player.o map.o keyandpass.o ghost.o main.o 
	g++ -o main main.o controller.o player.o keyandpass.o ghost.o map.o

main.o:
	g++ -c $(S_PATH)main.cpp $(INC) $(CFLAG)

controller.o:
	g++ -c $(S_PATH)controller.cpp $(INC) $(CFLAG)

player.o:
	g++ -c $(S_PATH)player.cpp $(INC) $(CFLAG)

map.o:
	g++ -c $(S_PATH)map.cpp $(INC) $(CFLAG)

keyandpass.o:
	g++ -c $(S_PATH)keyandpass.cpp $(INC) $(CFLAG)
	
ghost.o:
	g++ -c $(S_PATH)ghost.cpp $(INC) $(CFLAG)
	

run:
	./main ./include/level3.txt ./include/level4.txt

clean:
	rm -f main.o controller.o player.o map.o keyandpass.o ghost.o main