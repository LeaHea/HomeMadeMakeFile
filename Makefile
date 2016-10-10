make.x: MakeTree.o Reader.o DepGraph.o soln_main.o systemInterface.o GraphNode.o TreeNode.o
	g++ -ggdb MakeTree.o Reader.o DepGraph.o  soln_main.o systemInterface.o GraphNode.o TreeNode.o -o make.x

MakeTree.o: MakeTree.cpp MakeTree.hpp TreeNode.hpp GraphNode.hpp TreeNode.hpp
	g++ -ggdb MakeTree.cpp -o MakeTree.o -c

TreeNode.o: TreeNode.cpp TreeNode.hpp
	g++ -ggdb TreeNode.cpp -o TreeNode.o -c

GraphNode.o: GraphNode.cpp GraphNode.hpp
	g++ -ggdb GraphNode.cpp -o GraphNode.o -c

Reader.o: Reader.cpp Reader.hpp Token.hpp
	g++ -ggdb Reader.cpp -o Reader.o -c

DepGraph.o: DepGraph.cpp DepGraph.hpp GraphNode.hpp TreeNode.hpp systemInterface.hpp
	g++ -ggdb DepGraph.cpp -o DepGraph.o -c

soln_main.o: soln_main.cpp DepGraph.hpp
	g++ -ggdb soln_main.cpp -o soln_main.o -c

systemInterface.o: systemInterface.hpp systemInterface.cpp
	g++ -c systemInterface.cpp -o systemInterface.o

clean:
	rm -f *.o make.x *~
