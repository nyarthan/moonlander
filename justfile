alias help := default

default:
  @just --list

copy:
  cp ./keymap.c ./qmk_firmware/keyboards/zsa/moonlander/keymaps/default/keymap.c
  cp ./config.h ./qmk_firmware/keyboards/zsa/moonlander/keymaps/default/config.h
  cp ./rules.mk ./qmk_firmware/keyboards/zsa/moonlander/keymaps/default/rules.mk

build: copy
  pushd qmk_firmware && ./util/docker_build.sh zsa/moonlander && popd
  just extract
  just clean

extract:
  mkdir -p out
  cp ./qmk_firmware/zsa_moonlander_default.bin ./out/moonlander.bin

clean:
  git submodule deinit -f .
  git submodule update --init --recursive --checkout

flash:
  wally-cli ./out/moonlander.bin
