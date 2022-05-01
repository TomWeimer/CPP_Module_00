NAME		:=		awesomePhone
HEADER		:= 		-I	./includes


CPP			:=		c++

CPPFLAGS	:=		-Wall -Wextra -Werror -std=c++98

SRC			:=		src/main.cpp\
					src/PhoneBook.cpp\
					src/Contact.cpp\
					src/utils/queue.cpp\
					src/utils/print.cpp

OBJ			:= 		$(SRC:.cpp=.o)


all:		$(NAME)

$(NAME):	$(OBJ)
					@ $(CPP) $(CPPFLAGS) $(HEADER) $(OBJ) -o $(NAME)
					@ echo "\033[33m$(NAME) has been compiled !\033[0m"
%.o:	%.cpp
				@ $(CPP) $(CPPFLAGS) $(HEADER) -c $< -o $@
clean:
					$(RM) $(OBJ)
fclean:	clean
					$(RM) $(NAME)

re:		fclean all

.PHONY:	clean fclean re
	
