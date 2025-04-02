# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qliso <qliso@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 13:47:01 by qliso             #+#    #+#              #
#    Updated: 2025/04/01 16:32:55 by qliso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
#	VARIABLES   #
#################

NAME	= cpp05_ex00

# Source files list

SRCS	=	$(addsuffix .cpp, \
				main \
				Bureaucrat \
			)

HEADERS =	$(addsuffix .hpp, \
				Bureaucrat \
			)

# Object files generated in the .objs/ directory
OBJS_PATH	=	.objs/
OBJS		= $(SRCS:%c=$(OBJS_PATH)%.o)

# Compilation settings
CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -rf

#################
#	  RULES     #
#################

all	:	$(OBJS_PATH) $(NAME)

# Rule to link and create the final executable
$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)
		@echo "\033[1;32m$(NAME) compiled !\033[0m"

# Rule to compile object files
$(OBJS_PATH)%.o	:	$(SRCS)%.c $(HEADERS) | $(OBJS_PATH)
			$(CC) $(CPPFLAGS) -c $< .o $@

# Rule to create the object directory
$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

clean	:
		$(RM) $(OBJS_PATH)
		@echo "\033[1;31mObject files deleted !\033[0m"

fclean	:	clean
		$(RM) $(NAME)
		@echo "\033[1;31m$(NAME) deleted !\033[0m"

re		:	fclean all

.PHONY	:	all clean fclean re