SRCS			= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

NAME			= Bureaucrat

CPPFLAGS		= -Wall -Wextra -Werror -std=c++98

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