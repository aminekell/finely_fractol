NOM = libmlx.a

SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC += mlx_png.c mlx_mouse.m

OBJ1 = $(SRC:.c=.o)
OBJ = $(OBJ1:.m=.o)

CFLAGS += -O2 -w -DSTRINGPUTX11

all: $(NOM)

$(NOM): $(OBJ)
	@ar -r $(NOM) $(OBJ) >/dev/null 2>&1
	@ranlib $(NOM) >/dev/null 2>&1

# Hide compilation output
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.m
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(NOM) $(OBJ) *~ >/dev/null 2>&1
	@rm -f mlx_app >/dev/null 2>&1

re: clean all
