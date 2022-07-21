#include "trading_engine.hpp"

void TradingEngine::receive_input(std::string input_str){
	//Receives a single line of inputs
	/*
	Input is of the following format
	share_name [action n_shares value_per_share]...
	*/
	std::vector<std::string> inputs = parse_input(input_str);
	int n = inputs.size();
	std::string share_name,curr_action,n_share_str,price_str;
	action curr_ac;
	int n_shares;
	float value_per_share;
	share_name = inputs[0];
	int i=1;
	while(i < n){
		curr_action = inputs[i];
		if(curr_action == "BUY"){
			curr_ac = BUY;
		}else if(curr_action == "SELL"){
			curr_ac = SELL;
		}else if(curr_action == "BID"){
			curr_ac = BID;
		}else{
			curr_ac = OFFER;
		}
		n_share_str = inputs[i+1];
		price_str = inputs[i+2];
		n_shares = std::stoi(n_share_str);
		value_per_share = std::stof(price_str);
		this->share_names_list.push_back(share_name);
		this->action_list.push_back(curr_ac);
		this->n_shares_list.push_back(n_shares);
		this->value_per_share_list.push_back(value_per_share);
		i = i+3;
	}
	return;
}

void TradingEngine::print_share_table(){
	//Prints the trading table
	/*
	The trading table consists of 4 columns - share_names_list, action_list, n_shares_list
	and value_per_share_list
	*/
	int n = this->action_list.size();
	int i;
	for(i=0;i<n;i++){
		std::cout << "Share Name : " << this->share_names_list[i] 
		<< " Action : " << this->action_list[i] << " Number of Shares : " 
		<< this->n_shares_list[i] << " Value per Share : " << this->value_per_share_list[i] 
		<< std::endl;
	}
	return;
}

float TradingEngine::remove_element(int i){
	//Removes element and returns the value of those shares
	float val = this->value_per_share_list[i] * this->n_shares_list[i];
	this->share_names_list.erase(this->share_names_list.begin() + i);
	this->action_list.erase(this->action_list.begin() + i);
	this->n_shares_list.erase(this->n_shares_list.begin() + i);
	this->value_per_share_list.erase(this->value_per_share_list.begin() + i);
	return val;
}

float TradingEngine::make_trade(int i, int j){
	//Makes trade between shares at indices i and j in the trading table
	if(this->share_names_list[i] != this->share_names_list[j]){
		return 0.0;
	}
	if((this->action_list[i] == SELL || this->action_list[i] == OFFER) && (this->action_list[j] == BUY || this->action_list[j] == BID)){
		return TradingEngine::make_trade(j,i);
	}
	if(((this->action_list[i] == BUY || this->action_list[i] == BID) && (this->action_list[j] == SELL || this->action_list[j] == OFFER))){
		float net_profit = 0,tmp = 0, price_used;
		int n_shares_used;

		if(this->action_list[i] == BUY && this->action_list[j] == SELL){
			//Case for buying
			if(this->value_per_share_list[j] == this->value_per_share_list[i]){
				if(this->n_shares_list[i] < this->n_shares_list[j]){
					n_shares_used = this->n_shares_list[i];
					this->n_shares_list[i] = 0;
					this->n_shares_list[j] -= n_shares_used;
					net_profit = this->value_per_share_list[i]*n_shares_used;
					tmp = this->remove_element(i);
				}else if(this->n_shares_list[i] == this->n_shares_list[j]){
					n_shares_used = this->n_shares_list[i];
					net_profit = this->value_per_share_list[i]*n_shares_used;
					tmp = this->remove_element(i);
					tmp = this->remove_element(j);
				}else{
					n_shares_used = this->n_shares_list[j];
					this->n_shares_list[j] = 0;
					this->n_shares_list[i] -= n_shares_used;
					net_profit = this->value_per_share_list[i]*n_shares_used;
					tmp = this->remove_element(j);
				}
				return net_profit;
			}
		}
	}
	return 0.0;
}

float TradingEngine::run_engine(){
	int n = this->action_list.size();
	float net_profit = 0;
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			net_profit += this->make_trade(i,j);
		}
	}
	return net_profit;
}