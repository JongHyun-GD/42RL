NAME = K4Engine.a
HEADER =-I./include
SRCS =	source/Director.cpp \
		source/GameObject.cpp \
		source/Input.cpp \
		source/Scene.cpp  

OBJS=${SRCS:.cpp=.o}
all: $(NAME)
.cpp.o:$(SRCS)
	clang++ --std=c++20 $(HEADER) -c -o $@ $<
  
$(NAME): $(OBJS)
	ar rc $@ $^ 

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all


