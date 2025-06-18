
CC=cc

SDL_PATH := $(shell pwd)/SDL_LIB

NAME=Internet-Clicker

LOADING = LOADING/loading_loop.c \
          LOADING/ft_process_screens.c

OTHER = OTHER/ft_free.c \
        OTHER/init_text.c \
        OTHER/list_create.c

MENU = MENU/event_loop.c \
		MENU/menu_loop.c

TEXTURE = TEXTURE/ft_find_texture.c \
          TEXTURE/init_rect_for_texture.c \
          TEXTURE/load_texture.c

LEVEL_ONE = LEVEL1/level1_loop.c

ALL_FILE = main.c $(TEXTURE) $(LOADING) $(LEVEL_ONE) $(OTHER) $(MENU) 
SRC = $(addprefix GAME/, $(ALL_FILE))

RM=rm -f

OBJ = $(SRC:%.c=.obj/%.o)

CFLAGS = -Wall -Wextra -Werror -I$(SDL_PATH)/include/SDL2 -IGAME/INCLUDE -g
LDLIBS = -lm -L$(SDL_PATH)/lib -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS)

.obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# Variables
DESKTOP_INSTALL_PATH = ~/.local/share/applications
ICON_INSTALL_PATH = ~/.local/share/icons/hicolor/256x256/apps

# Assurez-vous que les répertoires existent
$(DESKTOP_INSTALL_PATH):
	mkdir -p $(DESKTOP_INSTALL_PATH)

$(ICON_INSTALL_PATH):
	mkdir -p $(ICON_INSTALL_PATH)

# Règle principale pour installer l'application et son icône
APP_NAME = Internet-Clicker
EXEC_PATH = $(shell pwd)/$(APP_NAME)
ICON_PATH = UTILITAIRE/icon.png
DESKTOP_FILE = $(APP_NAME).desktop

install: $(DESKTOP_INSTALL_PATH) $(ICON_INSTALL_PATH)
	# Copier l'icône
	cp $(ICON_PATH) $(ICON_INSTALL_PATH)/$(APP_NAME).png

	# Créer le fichier .desktop
	echo "[Desktop Entry]" > $(DESKTOP_FILE)
	echo "Version=1.0" >> $(DESKTOP_FILE)
	echo "Name=$(APP_NAME)" >> $(DESKTOP_FILE)
	echo "Comment=Un jeu de clicker basé sur les mèmes d'Internet" >> $(DESKTOP_FILE)
	echo "Exec=$(shell pwd)/launch.sh" >> $(DESKTOP_FILE)
	echo "Path=$(shell pwd)" >> $(DESKTOP_FILE)
	echo "Icon=$(APP_NAME)" >> $(DESKTOP_FILE)
	echo "Terminal=false" >> $(DESKTOP_FILE)
	echo "Type=Application" >> $(DESKTOP_FILE)
	echo "Categories=Utility;" >> $(DESKTOP_FILE)

	# Installer le fichier .desktop
	cp $(DESKTOP_FILE) $(DESKTOP_INSTALL_PATH)/
	chmod +x $(DESKTOP_INSTALL_PATH)/$(DESKTOP_FILE)

	# Mettre à jour la base de données des icônes
	xdg-icon-resource forceupdate --size 256

full_install:
	./rebuild_sdl2.sh
	make all
	make install
