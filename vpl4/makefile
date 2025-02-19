# Variáveis
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
TARGET = vpl_execution

# Objetos
OBJ = $(BUILD_DIR)/list.o $(BUILD_DIR)/main.o

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar list.cpp
$(BUILD_DIR)/list.o: $(SRC_DIR)/list.cpp $(INCLUDE_DIR)/list.hpp $(INCLUDE_DIR)/node.hpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Regra para compilar main.cpp
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/list.hpp $(INCLUDE_DIR)/node.hpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)
