#!/bin/bash

set -e  # Stop on first error

### CONFIGURATION ###
SDL_VERSION=2.32.6
INSTALL_DIR="$(pwd)/SDL_LIB"
BUILD_DIR="$(pwd)/SDL2-${SDL_VERSION}-build"
ARCHIVE_NAME="SDL2-${SDL_VERSION}.tar.gz"
SOURCE_URL="https://github.com/libsdl-org/SDL/releases/download/release-${SDL_VERSION}/${ARCHIVE_NAME}"

echo "📥 Téléchargement de SDL2 ${SDL_VERSION}..."
wget -O $ARCHIVE_NAME $SOURCE_URL

echo "📦 Extraction..."
tar -xzf $ARCHIVE_NAME
mv SDL2-${SDL_VERSION} $BUILD_DIR
cd $BUILD_DIR

echo "🔧 Préparation du build..."
./autogen.sh
mkdir build && cd build

echo "⚙️ Configuration avec --prefix=$INSTALL_DIR"
../configure --prefix="$INSTALL_DIR"

echo "🛠 Compilation..."
make -j$(nproc)

echo "📦 Installation locale dans SDL_LIB/"
make install

echo "🧹 Nettoyage des fichiers temporaires..."
cd ../..
rm -rf $BUILD_DIR $ARCHIVE_NAME

echo "✅ SDL2 ${SDL_VERSION} installé dans $INSTALL_DIR"
