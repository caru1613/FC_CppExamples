CC = g++
#CXXFLAGS = -std=gnu++17 -Wall -Werror 
CXXFLAGS = -std=gnu++17 -Wall
OBJS = main.o Person.o  Villiage.o utils1.o

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $<

all: $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o main

.PHONY: clean
clean:
	rm -f $(OBJS) main
