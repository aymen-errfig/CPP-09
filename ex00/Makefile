name = btc
FLAGS = -Wall -Wextra -Werror -std=c++98
CP = c++
srcs = src/BitcoinExchange.cpp src/DateTime.cpp src/utils.cpp main.cpp
heads = include/BitcoinExchange.hpp
objs = ${srcs:.cpp=.o}
RM = rm -f

all: $(name)

%.o: %.cpp $(heads)
	$(CP) $(FLAGS) -c $< -o $@ -g

$(name): $(objs)
	$(CP) $(FLAGS) $(objs) -o $(name) -fsanitize=address -g

clean:
	$(RM) $(objs)

fclean: clean
	$(RM) $(name)

re: fclean all