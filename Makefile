NAME	= lofl

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror $(DFLAG)

INC 	= ./inc
VPATH	= src/ src/ft_lib
SRCS	= lofl.c \
			ft_bzero.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_memcpy.c

TMP 	= tmp
OBJS	= $(SRCS:%.c=$(TMP)/%.o)
DPNDS	= $(SRCS:%.c=$(TMP)/%.d)

RM		=	rm -f

.PHONY:		all clean fclean re debug

# Linking
$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compiling
$(TMP)/%.o:	%.c $(TMP)/%.d | $(TMP)
			$(CC) $(CFLAGS) -MMD -I$(INC) -c $< -o $@

$(TMP):
	mkdir -p $@

$(DPNDS):

include $(wildcard $(DPNDS))

all:		$(NAME)

debug:
			$(MAKE) DFLAG="-g3" $(NAME)
clean:
			$(RM) -r $(TMP)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
