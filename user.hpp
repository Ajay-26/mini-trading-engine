#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

class User{
private:
	std::string password;
public:
	std::string username;
	std::vector<int> shares_held; //Store indices of shares held for quick access with trading engine
	float net_profit;
	User(std::string u_name, std::string p_word);
	void perform_action(std::string action);
};