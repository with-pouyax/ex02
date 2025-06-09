NAME = serialize
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
DEPFLAGS = -MMD -MP

SRCS = main.cpp \
       Serializer.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)


all: $(NAME)

$(NAME): $(OBJS)

$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
rm -f $(OBJS) $(DEPS)

fclean: clean
rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
