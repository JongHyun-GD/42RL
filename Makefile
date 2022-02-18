NAME=42RL

$(NAME) : all

all :
	clang++ main.cpp Input.cpp -g -o $(NAME) -I include -L lib -l SDL2-2.0.0
