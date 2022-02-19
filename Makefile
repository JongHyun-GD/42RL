NAME=42RL
HEADER = -I./source/
ENGINE = K4Engine
SRCS =	source/HelloWorld.cpp \
		source/main.cpp
$(NAME) : all

all :
	$(MAKE) -C ./$(ENGINE)
	clang++ $(SRCS) $(HEADER) -o $(NAME) -I./$(ENGINE)/include `sdl2-config --cflags --libs` $(ENGINE)/$(ENGINE).a

fclean:
	rm -f $(NAME)
re:fclean all
