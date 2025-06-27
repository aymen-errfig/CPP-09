name = RPN
FLAGS = -Wall -Wextra -Werror -std=c++98
CP = c++
srcs = RPN.cpp main.cpp
objs = ${srcs:.cpp=.o}
RM = rm -f

all: $(name)

%.o: %.cpp RPN.hpp
	$(CP) $(FLAGS) -c $< -o $@ -g

$(name): $(objs)
	$(CP) $(FLAGS) $(objs) -o $(name) -fsanitize=address -g

clean:
	$(RM) $(objs)

fclean: clean
	$(RM) $(name)

re: fclean all