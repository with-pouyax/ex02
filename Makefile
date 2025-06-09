# Name of the final executable
NAME = identify

# Compiler and compilation flags. The flags enforce the C++98 standard
# and enable common warnings.
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


# Source files and their corresponding object files
SRCS = main.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)


# Default rule builds the executable
all: $(NAME)


# Link the object files to create the final executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


# Compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Remove intermediate object files
clean:
	rm -f $(OBJS)


# Remove everything that can be rebuilt
fclean: clean
	rm -f $(NAME)


# Convenience target to rebuild from scratch
re: fclean all


# Mark these pseudo targets so Make doesn't look for files with these names
.PHONY: all clean fclean re
