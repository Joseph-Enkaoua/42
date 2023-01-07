#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(int argc, char **argv){
    int          i;
    std::string input;
    PhoneBook   book;

    if (argc == 1)
    {
        std::cout << BOLDBLUE << "Welcome to Borat's phonebook 👑" << std::endl;
        std::cout << GREEN << "type ADD, SEARCH or EXIT" << RESET << std::endl;
        i = -1;
        while (std::cin)
        {
            std::cout << GREEN << "Enter a command : " << RESET;
            std::getline(std::cin, input);
            if (!input.empty())
            {
                if (!input.compare("ADD")){
                    i++;
                    book.contact_list[i] = book.set_contact();
                }
                else if (!input.compare("SEARCH"))
                    book.search();
                else if (!input.compare("EXIT"))
                    exit(0);
                else
                    std::cout << YELLOW << "Please type one of the commands above" << RESET << std::endl;
            }
            else if (std::cin)
                std::cout << YELLOW << "Error: empty input" << RESET << std::endl;
            if (i == 7)
                i = -1;
        }
    }
    else
        std::cout << RED << "Error : too many arguments" << RESET << std::endl;
    (void)argv;
    return (0);
}