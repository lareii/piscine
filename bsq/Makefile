FLAGS = -Wall -Wextra -Werror
SRC = src/ft_atoi.c src/map.c src/row.c src/setup.c src/square.c main.c
NAME = bsq

all:
	@clang $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

map:
	@perl ./maps/map_gen.pl $(x) $(y) $(density) > ./maps/"$(x)x$(y)x$(density)"
