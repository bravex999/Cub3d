NAME        = cub3d
CC          = cc
CFLAGS      = -Wall -Werror -Wextra
INCLUDES    = -I includes -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(DIR_GNL)

DIR_CORE    = srcs/core
DIR_UTILS   = srcs/utils
DIR_MATH    = srcs/math/scalar
DIR_PARSER  = srcs/parser
DIR_VALIDATE= srcs/validate
DIR_GFX     = srcs/gfx
DIR_TEX     = srcs/textures
DIR_CAMERA  = srcs/camera
DIR_RENDER  = srcs/render
DIR_INPUT   = srcs/input
DIR_GNL		= srcs/gnl

# MiniLibX (Linux)
MLX_DIR     = libs/mlx/minilibx-linux
MLX_LIB     = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS_CORE    = main.c scene_init.c scene_init_2.c app_init_gfx.c
SRCS_UTILS   = error.c 
SRCS_MATH    = scalar_angle.c scalar_clamp.c scalar_norm.c scalar_normalize.c
SRCS_PARSER  = colors.c  headers.c  init.c  map_build.c  map_chars.c  map_closed_2.c  map_closed.c  map_spawn.c  map_stage.c  parse_precheck.c  parser.c  tex.c 
SRCS_VALIDATE= 
SRCS_GFX     = 
SRCS_TEX     = 
SRCS_CAMERA  = 
SRCS_RENDER  = 
SRCS_INPUT   = 
SRCS_GNL     = get_next_line.c
	

SRCS = \
  $(addprefix $(DIR_CORE)/,$(SRCS_CORE)) \
  $(addprefix $(DIR_UTILS)/,$(SRCS_UTILS)) \
  $(addprefix $(DIR_MATH)/,$(SRCS_MATH)) \
  $(addprefix $(DIR_PARSER)/,$(SRCS_PARSER)) \
  $(addprefix $(DIR_VALIDATE)/,$(SRCS_VALIDATE)) \
  $(addprefix $(DIR_GFX)/,$(SRCS_GFX)) \
  $(addprefix $(DIR_TEX)/,$(SRCS_TEX)) \
  $(addprefix $(DIR_CAMERA)/,$(SRCS_CAMERA)) \
  $(addprefix $(DIR_RENDER)/,$(SRCS_RENDER)) \
  $(addprefix $(DIR_INPUT)/,$(SRCS_INPUT)) \
  $(addprefix $(DIR_GNL)/,$(SRCS_GNL))

OBJS    = $(SRCS:.c=.o)
HEADERS = $(wildcard includes/*.h) $(wildcard $(DIR_GNL)/*.h)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)"

clean:
	rm -f $(OBJS)
	-$(MAKE) -C $(MLX_DIR) clean
	-$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	-$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

