#include "trading_engine.h"
#include <iostream>
#include <vector>
#include <string>

int main(){
	TradingEngine my_engine;
	std::string inputs = "MAVEN BUY 10 10.1 SELL 20 10.1";
	my_engine.receive_input(inputs);	
	inputs = "IMC SELL 20 10.1 BUY 30 10.1";
	my_engine.receive_input(inputs);
	my_engine.print_share_table();
	float p = my_engine.run_engine();
	std::cout << "Net profit = " << p << std::endl;
	my_engine.print_share_table();
	/*
	std::string inputs = "10";
	std::string newstr = inputs;
	newstr.append("0.112");
	float f = std::stof(newstr);
	std::cout << f << std::endl;
	*/
	return 0;
}
