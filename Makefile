NAME=42RL

$(NAME) : all

all :
	clang++ main.cpp -g -o $(NAME) -I include -I K4Engine -L lib -l SDL2-2.0.0
