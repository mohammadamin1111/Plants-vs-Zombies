CXX = g++ -g -std=c++20
SFML_LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OBJ_DIR = builds
SRC_DIR = src

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

EXE = $(OBJ_DIR)/pvz.out

all: $(EXE)

$(EXE): $(OBJ_FILES)
	$(CXX) $^ -o $@ $(SFML_LIBRARIES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXE)