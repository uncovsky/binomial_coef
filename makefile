CC = g++
CPPFLAGS = -g -Wall 
OBJS = main.o binomial.o


main : $(OBJS)
	$(CC) $(CPPFLAGS) -o main $(OBJS)
main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp
binomial.o : binomial.cpp
	$(CC) $(CPPFLAGS) -c binomial.cpp
clean:
	rm -f core main $(OBJS)
