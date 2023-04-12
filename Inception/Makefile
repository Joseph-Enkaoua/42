DOCKER_COMPOSE	= cd srcs/ && sudo docker compose
DATA_FOLDER 	= /home/henkaoua/data

all		:
			sudo mkdir -p $(DATA_FOLDER)
			sudo mkdir -p $(DATA_FOLDER)/wordpress
			sudo mkdir -p $(DATA_FOLDER)/database
			sudo chmod 777 /etc/hosts
			sudo echo "127.0.0.1 henkaoua.42.fr" >> /etc/hosts
			sudo echo "127.0.0.1 www.henkaoua.42.fr" >> /etc/hosts
			$(DOCKER_COMPOSE) up -d

up:
			${DOCKER_COMPOSE} up -d 

down:
			$(DOCKER_COMPOSE) down

clean:
			cd srcs/ && sudo docker compose down && sudo docker system prune --volumes --all --force

fclean:	clean
			cd .. && sudo rm -rf $(DATA_FOLDER)
			sudo docker network prune --force

re:	fclean all

.PHONY : all up down clean fclean re

# https://henkaoua.42.fr/wp-login.php

# see database tables:
# sudo docker exec -it mariadb mysql -u root -p (root_secret)
# SHOW DATABASES;
# use 'wordpress';
# SHOW TABLES;
# SELECT *  FROM wp_users;
