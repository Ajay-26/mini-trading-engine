#include "graph.hpp"

template <typename T>
node<T>::node(T p_data, int idx){
	this->data = p_data;
	this->index = idx;
}

template <typename T>
void node<T>::add_edge(node<T> *new_node){
	this->connected_nodes.push_back(new_node);
}

template <typename T>
void node<T>::print_neighbours(){
	/*
	Prints the neighbours of the node leaving a space in between
	Does not leave a line at the end
	*/
	int n = this->connected_nodes.size();
	int i;
	if(n == 0){
		std::cout << "No neighbours";
		return;
	}
	for(i=0;i<n;i++){
		std::cout << this->connected_nodes[i]->data << " ";
	}
	return;
}

template <typename T>
void Graph<T>::add_node(T data){
	int n = this->node_list.size();
	node<T> *new_node_ptr = new node(data,n);
	this->node_list.push_back(new_node_ptr);
	return;
}

template <typename T>
void Graph<T>::add_edge(int i, int j){
	/*
	Adds edge between node at index i in the graph and node at index j in the graph
	*/
	this->node_list[i]->add_edge(this->node_list[j]);
}

template <typename T>
void Graph<T>::print_graph(){
	int n =this->node_list.size();
	int i;
	for(i=0;i<n;i++){
		std::cout << this->node_list[i]->data << " - ";
		this->node_list[i]->print_neighbours();
		std::cout << "\n";
	}
	return;
}

int main(){
	Graph<float> g;
	g.add_node(2.3);
	g.add_node(4.6);
	g.add_node(6.9);
	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(0,2);
	g.print_graph();
}
