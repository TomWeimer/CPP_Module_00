##------------------------------------------------------------------------------##
## 								 THE TARGET										##
##------------------------------------------------------------------------------##
TARGET	:= awesomePhone

##------------------------------------------------------------------------------##
##								HEADERS											##
##------------------------------------------------------------------------------##
INCLUDE :=	-I ./includes

##------------------------------------------------------------------------------##
##								SOURCES											##
##------------------------------------------------------------------------------##
SRCS			:=	src/main.cpp\
					src/PhoneBook/PhoneBook.cpp\
					src/Contact/Contact.cpp\
					src/display/display.cpp

# Src directory
SRC_DIR		:=	src/
# Subdirectories of src
SRCS_SUBDIR	:=	src/Contact/ src/display/ src/PhoneBook/



##----------------------------------------------------------------------------------##
##								OBJECTS												##
##----------------------------------------------------------------------------------##
Objects = $(OBJS)

OBJ := $(SRCS:.cpp=.o)
# Objects directory
OBJ_DIR	:= obj/
# From str to obj/
OBJS := $(subst $(SRC_DIR), $(OBJ_DIR), $(OBJ))


##----------------------------------------------------------------------------------##
##							 OBJ_DIR CREATION										##
##----------------------------------------------------------------------------------##
MKDIR_P	:= mkdir -p
# Objects directory creation
NEWSUBDIR = $(MKDIR_P) $(addsuffix ;, $(subst $(SRC_DIR), $(OBJ_DIR), $(listObj)))


##------------------------------------------------------------------------------##
##									PRINT										##
##------------------------------------------------------------------------------##
ECHO	:= echo
# colors
RED		:= \033[1;31m
YEL		:= \033[1;33m
BLU		:= \033[1;34m
WHITE	:= \033[1;37m
GREEN	:= \033[1;32m
RESET	:= \033[0m


##------------------------------------------------------------------------------##
##								COMPILATION										##
##------------------------------------------------------------------------------##
CPP		:= g++-11
# Creation of the library
AR		:= ar rcs
# Compilation flags
CFLAGS	:= -Wall -Wextra -Werror -std=c++98 $(INCLUDE)
# explicit compilation
$(OBJ_DIR)%.o: %.cpp $(HEADERS)
	@ $(CPP) $(CFLAGS) $(INCLUDE)  -c $< -o $@
# vpath
VPATH := $(SRC_DIR) $(OBJ_DIR) $(SRCS_SUBDIR)

##------------------------------------------------------------------------------##
##									MAKE RULES									##
##------------------------------------------------------------------------------##
all:	$(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)
	@ $(foreach listObj, $(SRCS_SUBDIR), $(NEWSUBDIR))

$(TARGET):	$(SRCS) $(Objects)
	 @ $(CPP) $(CFLAGS) $(Objects) -o $(TARGET) 
	 @ $(ECHO) "$(GREEN)$(TARGET) compiled with success!$(RESET)"

clean:
	@ $(ECHO) "\n $(RED)removing: $(RESET) $(OBJ_DIR) $(Objects)\n$(RESET)"
	@ rm -rf $(Objects)
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ $(ECHO) "\n $(RED)removing: $(RESET) $(TARGET)\n"
	@ rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re bonus