# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

# Flags de compilação
CC = g++
CCFLAGS = -Wall -std=c++11 -I$(INCLUDE_DIR)


# Arquivos .cpp e .o
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) 
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))  

# Arquivo target executável - main.exe
EXEC = $(BIN_DIR)/main.exe

# Regras
all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CC) $(CCFLAGS) $^ -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# Parâmetros de dependências entre arquivos
$(OBJ_DIR)/Reversi.o: $(INCLUDE_DIR)/Reversi.hpp $(INCLUDE_DIR)/Jogo.hpp

$(OBJ_DIR)/Liga4.o: $(INCLUDE_DIR)/Liga4.hpp $(INCLUDE_DIR)/Jogo.hpp

$(OBJ_DIR)/JogoDaVelha.o: $(INCLUDE_DIR)/JogoDaVelha.hpp $(INCLUDE_DIR)/Jogo.hpp

$(OBJ_DIR)/CampoMinado.o: $(INCLUDE_DIR)/CampoMinado.hpp $(INCLUDE_DIR)/Jogo.hpp
 
$(OBJ_DIR)/Sistema.o: $(INCLUDE_DIR)/Sistema.hpp $(INCLUDE_DIR)/Jogador.hpp

$(OBJ_DIR)/Partida.o: $(INCLUDE_DIR)/Jogo.hpp $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Sistema.hpp \
					  $(INCLUDE_DIR)/Reversi.hpp $(INCLUDE_DIR)/Liga4.hpp $(INCLUDE_DIR)/JogoDaVelha.hpp

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/Sistema.hpp $(INCLUDE_DIR)/Jogador.hpp \
                   $(INCLUDE_DIR)/Jogo.hpp $(INCLUDE_DIR)/JogoDaVelha.hpp \
                   $(INCLUDE_DIR)/Reversi.hpp $(INCLUDE_DIR)/Liga4.hpp $(INCLUDE_DIR)/Partida.hpp	

clean:
	del /f obj\*.o bin\*.exe bin\*.txt

.PHONY: all clean
