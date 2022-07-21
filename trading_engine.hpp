#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "utils.hpp"

enum action {BUY = 0, SELL,BID,OFFER};

class TradingEngine{
public:
	std::vector<std::string> share_names_list;
	std::vector<action> action_list;
	std::vector<int> n_shares_list;
	std::vector<float> value_per_share_list;
	void receive_input(std::string input_str);
	void print_share_table();
	float make_trade(int i, int j);
	float remove_element(int i);
	float run_engine();
};