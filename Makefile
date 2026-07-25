PRESET ?= Clang-Debug
PROJECT := Game

ifeq ($(OS),Windows_NT)
	EXE := build/$(PRESET)/bin/$(PROJECT).exe
	RUN := "$(EXE)"
	RM := rmdir /s /q
else
	EXE := build/$(PRESET)/bin/$(PROJECT)
	RUN := ./$(EXE)
	RM := rm -rf
endif

.PHONY: all setup build run clean rebuild br

all: setup build

setup:
	cmake --preset $(PRESET)

build:
	cmake --build --preset $(PRESET)

run:
	$(RUN)

clean:
	cmake -E rm -rf build/ clangd/

rebuild: clean setup build

br: build run
