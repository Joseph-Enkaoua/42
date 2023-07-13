#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../headers/Server.hpp"
#include "../headers/Globals.h"

void	signal_handler(int signum) {
	if (signum == SIGINT)
		g_terminateRequested = true;
}

int main(int argc, char **argv) {
	struct sigaction	sa;

	if (argc != 3) {
		std::cout << "Usage: ./ircserv <port> <password>" << std::endl;
		return 1;	
	}

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGINT, &sa, NULL);

	Server	server("127.0.0.1", atoi(argv[1]), argv[2]);
	server.run();

	return 0;
}
