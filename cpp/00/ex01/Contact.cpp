#include "Contact.hpp"

Contact::Contact(void){
    this->is_empty = 1;
}

Contact::~Contact(void){
}

void    Contact::set_firstname(std::string str){
    this->firstname = str;
}

void    Contact::set_lastname(std::string str){
    this->lastname = str;
}

void    Contact::set_nickname(std::string str){
    this->nickname = str;
}

void    Contact::set_number(std::string str){
    this->number = str;
}

void    Contact::set_secret(std::string str){
    this->secret = str;
}

std::string Contact::get_fisrtname(void){
    return (this->firstname);
}

std::string Contact::get_lastname(void){
    return (this->lastname);
}

std::string Contact::get_nickname(void){
    return (this->nickname);
}

std::string Contact::get_number(void){
    return (this->number);
}

std::string Contact::get_secret(void){
    return (this->secret);
}

