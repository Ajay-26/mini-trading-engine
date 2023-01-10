#include "user.h"

User::User(std::string u_name, std::string p_word){
	this->username = u_name;
	this->password = p_word;
	this->net_profit = 0;
}

void User::perform_action(std::string action){
	return;	
}