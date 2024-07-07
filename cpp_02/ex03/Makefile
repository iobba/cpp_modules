SRCS			= bsp.cpp main.cpp Fixed.cpp Point.cpp 

NAME			= checker

CPPFLAGS			= -Wall -Wextra -Werror -std=c++98

RM				= rm -f

AR				= ar rc 

OBJS			= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	c++ ${OBJS} -o ${NAME}

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all