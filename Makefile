NAME=42RL

$(NAME) : all

all :
	clang++ main.cpp Input.cpp MemoryPool.cpp -g -o $(NAME) -I include `sdl2-config --cflags --libs`
