NAME=42RL

$(NAME) : all

all :
	clang++ main.cpp -o $(NAME) -I./K4Engine/include `sdl2-config --cflags --libs` K4Engine/K4Engine.a

fclean:
	rm -f $(NAME)
re:fclean all