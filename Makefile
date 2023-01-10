#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -std=c++17 -O2

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lm

#This is the target that compiles our executable
main: main.o trading_engine.o utils.o user.o order.o
	$(CC) main.o trading_engine.o user.o utils.o order.o -o main $(COMPILER_FLAGS) $(LINKER_FLAGS)

main.o: main.cpp 
	$(CC) -c main.cpp -o main.o $(COMPILER_FLAGS)

trading_engine.o: trading_engine.cpp trading_engine.h order.h utils.h user.h
	$(CC) -c trading_engine.cpp -o trading_engine.o $(COMPILER_FLAGS)

order.o: order.cpp order.h
	$(CC) -c order.cpp -o order.o $(COMPILER_FLAGS)

utils.o: utils.cpp utils.h
	$(CC) -c utils.cpp -o utils.o $(COMPILER_FLAGS)

user.o: user.cpp user.h
	$(CC) -c user.cpp -o user.o $(COMPILER_FLAGS)

clean:
	rm *.o main