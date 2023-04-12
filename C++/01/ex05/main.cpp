#include "Harl.hpp"

int	main(void){
	Harl	harl;

	harl.complain("error");
	harl.complain("DEBUG");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("INFODEBUG");
	harl.complain("INFOO");
	harl.complain("WARNING");
	harl.complain("vivi");
	harl.complain("WHAT?");
	return 0;
}