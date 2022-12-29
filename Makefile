# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 12:46:29 by ybenlafk          #+#    #+#              #
#    Updated: 2022/12/29 12:51:35 by ybenlafk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME= client
S_NAME= server

HEADER= minitalk.h

S_SRCS= utils.c server.c
C_SRCS= utils.c client.c
S_OBGJ= $(S_SRCS:.c=.o)
C_OBGJ= $(C_SRCS:.c=.o)
CC = cc 
CFLAGS = 
FRM = rm -rf

all: $(C_NAME) $(S_NAME)

$(C_NAME): $(C_OBGJ)
	$(CC) $(CFLAGS) $(C_OBGJ) -o $(C_NAME)

$(S_NAME): $(S_OBGJ)
	$(CC) $(CFLAGS) $(S_OBGJ) -o $(S_NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(FRM) $(S_OBGJ) $(C_OBGJ)

fclean: clean
	$(FRM) $(S_NAME) $(C_NAME)

re: fclean all