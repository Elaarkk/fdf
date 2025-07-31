#CONFIG

NAME = fdf
CC = gcc
DEPFLAGS = -MP -MD
RM = rm -rf

#FILES

INC = ./includes/

SRCS = main.c mlx_functions.c exit_functions.c get_next_line/get_next_line.c \
			 get_next_line/get_next_line_utils.c map_parsing.c ft_split.c utils.c \
			 utils_visual.c maths_fdf.c bresenham.c mlx_functions2.c \

OBJDIR = ./obj

MLXDIR = ./mlx

MLX = $(MLXDIR)/libmlx.a

OBJS = $(addprefix $(OBJDIR)/,$(patsubst %.c,%.o,$(SRCS)))

DEP = $(OBJ:.o=.d)

#FLAGS

FLAGS = -Wall -Wextra -Werror -I$(INC) -I$(MLXDIR) -I/usr/include/ -g3

### RAJOUTER WERROR

# Libraries and Linker Flags
LIB =  $(MLX)
MLXFLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

#COMMANDS

all : $(NAME) $(MLX)

$(OBJDIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(DEPFLAGS) -c $< -o $@ -lm

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB) $(MLXFLAGS) -lm
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJDIR)
	@echo "$(YELLOW)object files deleted.$(DEFAULT)"

fclean : clean
	$(RM) $(NAME)
	@echo "$(RED)all files deleted.$(DEFAULT)"

re : fclean all

.PHONY:
		fdf all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
