ALL =  \
  bin/makerandom \
  bin/netflow_skeleton \
  bin/netflow_dfs_edge_list \
  bin/netflow_dfs_v_no_delete \
  bin/netflow_dfs_v_delete \
  bin/netflow_dfs_list_pf \
  bin/netflow_dfs_list_pb \
  bin/netflow_dfs_greedy \
  bin/netflow_dijkstra \

all: $(ALL)

ek:  bin/netflow_edmonds_karp 

clean:
	rm -f bin/*

CFLAGS = -O3 -Wall -Wextra -std=c++98

bin/makerandom: src/makerandom.cpp
	g++ $(CFLAGS) -o bin/makerandom src/makerandom.cpp

bin/netflow_skeleton: src/netflow_skeleton.cpp
	g++ $(CFLAGS) -o bin/netflow_skeleton src/netflow_skeleton.cpp

bin/netflow_dfs_edge_list: src/netflow_dfs_edge_list.cpp
	g++ $(CFLAGS) -o bin/netflow_dfs_edge_list src/netflow_dfs_edge_list.cpp

bin/netflow_dfs_v_no_delete: src/netflow_dfs_v_no_delete.cpp
	g++ $(CFLAGS) -o bin/netflow_dfs_v_no_delete src/netflow_dfs_v_no_delete.cpp

bin/netflow_dfs_v_delete: src/netflow_dfs_v_delete.cpp
	g++ $(CFLAGS) -o bin/netflow_dfs_v_delete src/netflow_dfs_v_delete.cpp

bin/netflow_dfs_greedy: src/netflow_dfs_greedy.cpp
	g++ $(CFLAGS) -o bin/netflow_dfs_greedy src/netflow_dfs_greedy.cpp

bin/netflow_dfs_list_pf: src/netflow_dfs_list_pf.cpp
	g++ $(CFLAGS) -o bin/netflow_dfs_list_pf src/netflow_dfs_list_pf.cpp

bin/netflow_dfs_list_pb: src/netflow_dfs_list_pb.cpp
	g++ $(CFLAGS) -o bin/netflow_dfs_list_pb src/netflow_dfs_list_pb.cpp

bin/netflow_dijkstra: src/netflow_dijkstra.cpp
	g++ $(CFLAGS) -o bin/netflow_dijkstra src/netflow_dijkstra.cpp

bin/netflow_edmonds_karp: src/netflow_edmonds_karp.cpp
	g++ $(CFLAGS) -o bin/netflow_edmonds_karp src/netflow_edmonds_karp.cpp

