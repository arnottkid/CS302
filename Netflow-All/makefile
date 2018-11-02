ALL = netflow_skeleton  netflow_dfs_edge_list netflow_dfs_v_no_delete makerandom  \
      netflow_dfs_v_delete netflow_dfs_list_pf netflow_dfs_list_pb \
      netflow_dfs_greedy netflow_dijkstra netflow_edmonds_karp

all: $(ALL)

clean:
	rm -f *.o $(ALL)

.SUFFIXES: .cpp .o .out .hist .jgr .jps .eps .nt .bib .tab .tex .dvi .fig .txt .ps .pdf .bin .od .odh .odd .ppm .gif

.cpp.o: 
	g++ -O3 -c $*.cpp


makerandom: makerandom.o
	g++ -O3 -o makerandom makerandom.cpp

netflow_skeleton: netflow_skeleton.o
	g++ -O3 -o netflow_skeleton netflow_skeleton.cpp

netflow_dfs_edge_list: netflow_dfs_edge_list.o
	g++ -O3 -o netflow_dfs_edge_list netflow_dfs_edge_list.cpp

netflow_dfs_v_no_delete: netflow_dfs_v_no_delete.o
	g++ -O3 -o netflow_dfs_v_no_delete netflow_dfs_v_no_delete.cpp

netflow_dfs_v_delete: netflow_dfs_v_delete.o
	g++ -O3 -o netflow_dfs_v_delete netflow_dfs_v_delete.cpp

netflow_dfs_greedy: netflow_dfs_greedy.o
	g++ -O3 -o netflow_dfs_greedy netflow_dfs_greedy.cpp

netflow_dfs_list_pf: netflow_dfs_list_pf.o
	g++ -O3 -o netflow_dfs_list_pf netflow_dfs_list_pf.cpp

netflow_dfs_list_pb: netflow_dfs_list_pb.o
	g++ -O3 -o netflow_dfs_list_pb netflow_dfs_list_pb.cpp

netflow_dijkstra: netflow_dijkstra.o
	g++ -O3 -o netflow_dijkstra netflow_dijkstra.cpp

netflow_edmonds_karp: netflow_edmonds_karp.o
	g++ -O3 -o netflow_edmonds_karp netflow_edmonds_karp.cpp

