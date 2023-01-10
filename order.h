#pragma once
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

class Order{
public:
	int order_id;
	std::string ticker_name;
	bool buy;
	double price;
	int n_shares;
	Order(int id, std::string name, bool b, double p, int n);
};