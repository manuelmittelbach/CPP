NAME        = Serena_love

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRC         = ClapTrap.cpp ScavTrap.cpp main.cpp

OBJ         = $(SRC:.cpp=.o)
DEP 		= $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re