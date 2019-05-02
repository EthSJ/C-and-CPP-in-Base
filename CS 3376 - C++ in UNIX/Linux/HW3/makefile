
#CS 3376

CXX = g++
CXXFLAGS = -Wall
OBJS = HW3.o

%o:%cc
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -O $< -o $@

all: HW3

clean:
	rm -f $(OBJS) HW3
HW3:$(OBJS)
	g++ -o $@ $(OBJS)
