#pragma once
#include <iostream>
#include <vector>
#include <string>

template <typename T>
class node{
public:
	int index;
	T data;
	std::vector<node<T>*> connected_nodes;
	node(T p_data, int idx);
	void add_edge(node *new_node);
	void print_neighbours();
};

template <typename T>
class Graph{
	//Singly connected graph
public:
	std::vector<node<T> *> node_list;
	void add_node(T data);
	void add_edge(int i, int j);
	void print_graph();
};