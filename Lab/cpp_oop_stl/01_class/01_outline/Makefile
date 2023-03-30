CC = g++
CXXFLAGS = -std=gnu++17 -Wall -Werror 
OBJS = main.o

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $<

all: $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o main

.PHONY: clean
clean:
	rm -f $(OBJS) main
