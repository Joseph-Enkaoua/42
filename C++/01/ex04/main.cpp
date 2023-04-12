#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

void	replace_str(std::string& input, std::string to_replace, std::string replace_with){
	std::string	str = "";
	int			i;
	int			len = to_replace.size();

	i = 0;
	while (input[i]){
		if (input.compare(i, len, to_replace) == 0){
			str = str + replace_with;
			i += len;
		}
		else
			str = str + input[i++];
	}
	input = str;
}

int	main(int argc, const char *argv[]){
    std::ifstream	input_file;
	std::ofstream	newfile;
	std::string		input;
	std::string		newfile_name;
	
	if (argc != 4){
		std::cerr << "Error: wrong parameters" << std::endl; 
		return 1;
	}
	std::string	file_name = argv[1], to_replace = argv[2], replace_with = argv[3];
	if (file_name.empty() || to_replace.empty() || replace_with.empty()){
		std::cerr << "Error: empty parameter" << std::endl; 
		return 1;
	}
	input_file.open(file_name.c_str(), std::ifstream::in);
	if (!input_file){
		std::cerr << "Error: incorrect file" << std::endl; 
		return 1;
	}
	newfile_name = file_name + ".replace";
	newfile.open(newfile_name.c_str(), std::ifstream::out | std::ifstream::trunc);
	std::getline (input_file, input, '\0');
	replace_str(input, to_replace, replace_with);
	newfile << input;
	input_file.close();
	newfile.close();
	return 0;
}