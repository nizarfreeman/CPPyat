C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Bureaucrat.cpp AForm.cpp
HEADER = Bureaucrat.hpp AForm.hpp
OBJ = $(SRC:.cpp=.o)
NAME = a.out

all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re