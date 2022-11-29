#===========================Makefile================================#

CC=gcc
IDIR = common/inc
CFLAGS=-Wall -I$(IDIR)
OBJS = main.o graph.o parse_flight_data.o 

all: eseguibile

eseguibile: $(OBJS)
    $(CC) $(CFLAGS) $^ -o eseguibile

main.o: main.cpp graph.hpp
    $(CC) -c $(CFLAGS) main.cpp

graph.o: graph.cpp graph.hpp
    $(CC) -c $(CFLAGS) graph.c

parse_flight_data.o: parse_flight_data.cpp parse_flight_data.hpp
    $(CC) -c $(CFLAGS) parse_flight_data.c

clean:
    rm -rf *.o eseguibile

