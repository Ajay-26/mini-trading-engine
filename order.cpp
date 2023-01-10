#include "order.h"

Order::Order(int id, std::string ticker, bool b, double p, int n){
	this->order_id = id;
	this->ticker_name = ticker;
	this->buy = b;
	this->price = p;
	this->n_shares = n;
}