ALL =  \
  bin/makerandom \
  bin/nf_tool

LIB = lib/libnetwork_flow.a
OBJS = obj/network_flow_basics.o

all: $(ALL)

clean:
	rm -f bin/* lib/*

$(LIB): $(OBJS)
	ar r $(LIB) $(OBJS)
	ranlib $(LIB)

CFLAGS = -O3 -Iinclude -Wall -Wextra -std=c++98

bin/makerandom: src/makerandom.cpp
	g++ $(CFLAGS) -o bin/makerandom src/makerandom.cpp

bin/nf_tool: src/nf_tool.cpp $(LIB)
	g++ $(CFLAGS) -o bin/nf_tool src/nf_tool.cpp $(LIB)

obj/network_flow_basics.o: include/network_flow.hpp src/network_flow_basics.cpp
	g++ $(CFLAGS) -c -o obj/network_flow_basics.o src/network_flow_basics.cpp
