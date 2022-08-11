CC = g++
CFLAGS = -O2 -march=native
NAME = main
NAME_MODULE = module

run:
	clear
	$(CC) $(NAME).cpp $(NAME_MODULE).cpp -o $(NAME)
	./$(NAME)