#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void){
}

PhoneBook::~PhoneBook(void){
}

static void    edit_str(std::string str){
    int len;

    std::cout << "|";
    len = str.size();
    if (len > 10)
        std::cout << str.substr(0, 9) << ".";
    else if (len < 10)
        std::cout << std::setw(10) << str;
    else
        std::cout << str;
}

void    PhoneBook::show_contact_details(int i){
    std::cout << BLUE << "First name: " << RESET;
    std::cout << this->contact_list[i].get_fisrtname() << std::endl;
    std::cout << BLUE << "Last name: " << RESET;
    std::cout << this->contact_list[i].get_lastname() << std::endl;
    std::cout << BLUE << "Nickname: " << RESET;
    std::cout << this->contact_list[i].get_nickname() << std::endl;
    std::cout << BLUE << "Phone number: " << RESET;
    std::cout << this->contact_list[i].get_number() << std::endl;
    std::cout << BLUE << "Dark secret: " << RESET;
    std::cout << this->contact_list[i].get_secret() << std::endl;
}

void    PhoneBook::search(void){
    int         i;
    int         input;
    std::string str;

    i = -1;
    while (++i <= 7)
    {
        if (!this->contact_list[i].is_empty){
            std::cout << "------------------------------------" << std::endl;
            std::cout << "|" << YELLOW << (i + 1) << RESET;
            edit_str(this->contact_list[i].get_fisrtname());
            edit_str(this->contact_list[i].get_lastname());
            edit_str(this->contact_list[i].get_nickname());
            std::cout << "|" << std::endl;
            std::cout << "------------------------------------" << std::endl;
        }
        else
            break;
    }
    std::cout << GREEN << "Type contact index number : " << RESET;
    std::getline(std::cin, str);
    std::istringstream(str) >> input;
    if (input < 1 || input > i)
        std::cout << "Error: Invalid index" << std::endl;
    else
        show_contact_details(input - 1);
}

Contact PhoneBook::set_contact(void){
    int         empty;
    Contact     person;
    std::string input;

    empty = 1;
    while (empty && std::cin)
    {
        std::cout << "Insert first name: ";
        std::getline(std::cin, input);
        if (input.empty() && std::cin)
            std::cout << "Empty input isn't cool 🤢 " << std::endl;
        else
            empty = 0;
    }
    person.set_firstname(input);
    empty = 1;
    while (empty && std::cin)
    {
        std::cout << "Insert last name: ";
        std::getline(std::cin, input);
        if (input.empty() && std::cin)
            std::cout << "Empty input isn't cool 🤢 " << std::endl;
        else
            empty = 0;
    }
    person.set_lastname(input);
    empty = 1;
    while (empty && std::cin)
    {
        std::cout << "Insert nickname: ";
        std::getline(std::cin, input);
        if (input.empty() && std::cin)
            std::cout << "Empty input isn't cool 🤢 " << std::endl;
        else
            empty = 0;
    }
    person.set_nickname(input);
    empty = 1;
    while (empty && std::cin)
    {
        std::cout << "Insert phone number: ";
        std::getline(std::cin, input);
        if (input.empty() && std::cin)
            std::cout << "Empty input isn't cool 🤢 " << std::endl;
        else
            empty = 0;
    }
    person.set_number(input);
    empty = 1;
    while (empty && std::cin)
    {
        std::cout << "Insert dark secret: ";
        std::getline(std::cin, input);
        if (input.empty() && std::cin)
            std::cout << "Empty input isn't cool 🤢 " << std::endl;
        else
            empty = 0;
    }
    person.set_secret(input);
    if (std::cin)
        std::cout << CYAN << "Contact saved successfuly !" << RESET << std::endl;
    person.is_empty = 0;
    return (person);
}
