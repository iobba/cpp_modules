SRCS			= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

NAME			= Zombie

CFLAGS			= -Wall -Wextra -Werror -std=c++98

RM				= rm -f

AR				= ar rc 

OBJS			= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	c++ ${CFLAGS} ${OBJS} -o ${NAME}

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
