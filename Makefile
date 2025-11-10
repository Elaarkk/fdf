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

OBJS = $(addprefix $(OBJDIR)/,$(patsubst %.c,%.o,$(SRCS)))

DEP = $(OBJ:.o=.d)


MLX_GIT = https://github.com/42paris/minilibx-linux.git

MLXDIR = ./mlx

MLX = $(MLXDIR)/libmlx.a

#FLAGS

FLAGS = -Wall -Wextra -Werror -I$(INC) -I$(MLXDIR) -I/usr/include/ -g3

LIB =  $(MLX)
MLXFLAGS = -L$(MLXDIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

#COMMANDS

all : $(MLX) $(NAME)

$(MLX):
	@if [ ! -d "$(MLXDIR)" ]; then \
		echo "$(YELLOW)Cloning MiniLibX...$(DEFAULT)" ; \
		git clone $(MLX_GIT) $(MLXDIR) ; \
	else \
		echo "$(GREEN)MiniLibX directory already exists.$(DEFAULT)" ; \
	fi
	@echo "$(YELLOW)Compiling MiniLibX...$(DEFAULT)"
	@$(MAKE) -C $(MLXDIR)
	@echo "$(GREEN)MiniLibX compiled!$(DEFAULT)"

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB) $(MLXFLAGS)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

$(OBJDIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJDIR)
	@if [ -d "$(MLXDIR)" ]; then $(MAKE) -C $(MLXDIR) clean; fi
	@echo "$(YELLOW)Object files deleted.$(DEFAULT)"

fclean : clean
	$(RM) $(NAME)
	$(RM) -r $(MLXDIR)
	@echo "$(RED)All files deleted, including MLX directory.$(DEFAULT)"

re : fclean all

.PHONY: all clean fclean re bonus fdf

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m