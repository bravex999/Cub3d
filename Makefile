NAME        = cub3d
CC          = cc
CFLAGS      = -Wall -Werror -Wextra
INCLUDES    = -I include -I $(MLX_DIR)

# Directorios (11 módulos del plan)
DIR_CORE    = src/core              # hooks + cleanup + main
DIR_UTILS   = src/utils             # utils/error
DIR_MATH    = src/math/scalar       
DIR_IO      = src/io                # io/parse_cub
DIR_VALIDATE= src/io                # io/validate_map
DIR_GFX     = src/gfx               # gfx/mlx_init
DIR_TEX     = src/textures          # textures/load
DIR_CAMERA  = src/camera            # camera/player_setup
DIR_RENDER  = src/render            # render/core
DIR_INPUT   = src/input             # input + collision

# MiniLibX (Linux)
MLX_DIR     = libs/mlx/minilibx-linux
MLX_LIB     = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm -lz

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

# Fuentes por módulo (ajusta a tus nombres reales)
SRCS_CORE    = 
SRCS_UTILS   = 
SRCS_MATH    = scalar_angle.c scalar_clamp.c scalar_norm.c scalar_normalize.c
SRCS_IO      = 
SRCS_VALIDATE= 
SRCS_GFX     = 
SRCS_TEX     = 
SRCS_CAMERA  = 
SRCS_RENDER  = 
SRCS_INPUT   = 

SRCS = \
  $(addprefix $(DIR_CORE)/,$(SRCS_CORE)) \
  $(addprefix $(DIR_UTILS)/,$(SRCS_UTILS)) \
  $(addprefix $(DIR_MATH)/,$(SRCS_MATH)) \
  $(addprefix $(DIR_IO)/,$(SRCS_IO)) \
  $(addprefix $(DIR_VALIDATE)/,$(SRCS_VALIDATE)) \
  $(addprefix $(DIR_GFX)/,$(SRCS_GFX)) \
  $(addprefix $(DIR_TEX)/,$(SRCS_TEX)) \
  $(addprefix $(DIR_CAMERA)/,$(SRCS_CAMERA)) \
  $(addprefix $(DIR_RENDER)/,$(SRCS_RENDER)) \
  $(addprefix $(DIR_INPUT)/,$(SRCS_INPUT))

OBJS    = $(SRCS:.c=.o)
HEADERS = $(wildcard include/*.h)

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

