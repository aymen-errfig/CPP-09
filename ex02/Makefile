name = PmergeMe
FLAGS = -Wall -Wextra -Werror -std=c++98
CP = c++
srcs = PmergeMe.cpp main.cpp
objs = ${srcs:.cpp=.o}
RM = rm -f

all: $(name)

%.o: %.cpp PmergeMe.hpp
	$(CP) $(FLAGS) -c $< -o $@

$(name): $(objs)
	$(CP) $(FLAGS) $(objs) -o $(name)

clean:
	$(RM) $(objs)

fclean: clean
	$(RM) $(name)

re: fclean all