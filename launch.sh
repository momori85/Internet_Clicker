#!/bin/bash
# Forcer l'utilisation de SDL locale dans ~/.local/lib
export PATH=$(pwd)/SDL_LIB/bin:$PATH
export PKG_CONFIG_PATH=$(pwd)/SDL_LIB/lib/pkgconfig
export LD_LIBRARY_PATH=$(pwd)/SDL_LIB/lib:$LD_LIBRARY_PATH

# Lancer le jeu depuis son dossier
cd "$(dirname "$0")"
exec ./Internet-Clicker

