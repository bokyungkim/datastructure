all: array

array:
	gcc -g dijkstra_array.c ../../week4/graph/arraygraph/arraygraph.c -o array.out
	./array.out

linked:
	gcc -g dijkstra_linked.c ../../week4/graph/linkedgraph/linkedgraph.c ../../week1/linkedlist/linkedlist.c -o linked.out

clean:
	rm array.out

fclean: clean
	rm -rf array.out.dSYM

re: fclean all

.PHONY: all array linked clean re