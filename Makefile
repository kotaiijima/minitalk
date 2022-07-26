CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
SERVER	=	server
CLIENT	=	client
NAME	=	minitalk

$(NAME):	$(SERVER) $(CLIENT)

server:		server.c mini_utils.c
			$(CC) $(CFLAGS) server.c mini_utils.c -o $(SERVER)

client:		client.c mini_utils.C
			$(CC) $(CFLAGS) client.c mini_utils.c -o $(CLIENT)

all:		$(NAME)

clean:
			rm -f server.o client.o mini_utils.o

fclean:		clean
			rm -f $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re
