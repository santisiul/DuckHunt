
EXEC := DuckHunt

DIRSRC := src/
DIROBJ := obj/
DIRHEA := include/

CXX := g++ -std=c++14

# Flags de compilación -----------------------------------------------
CXXFLAGS := -I$(DIRHEA) -Wall `pkg-config --cflags OIS OGRE` 

# Flags del linker ---------------------------------------------------
LDFLAGS := `pkg-config --libs-only-L OGRE`
LDLIBS := `pkg-config --libs-only-l gl OIS OGRE` -lstdc++ -lboost_system

CXXFLAGS += -I/usr/local/include/cegui-0/CEGUI -I/usr/local/include/cegui-0

LDFLAGS += -lCEGUIBase-0 -lCEGUIOgreRenderer-0

# Modo de compilación (-mode=release -mode=debug) --------------------
ifeq ($(mode), release) 
	CXXFLAGS += -O2 -D_RELEASE
else 
	CXXFLAGS += -g -D_DEBUG
	mode := debug
endif

# Obtención automática de la lista de objetos a compilar -------------
OBJS := $(subst $(DIRSRC), $(DIROBJ), \
	$(patsubst %.cpp, %.o, $(wildcard $(DIRSRC)*.cpp)))

.PHONY: all clean

all: info dirs $(EXEC)

info:
	@echo '------------------------------------------------------'
	@echo '>>> Using mode $(mode)'
	@echo '    (Please, call "make" with [mode=debug|release])  '
	@echo '------------------------------------------------------'

dirs:
	mkdir -p $(DIROBJ)

# Enlazado -----------------------------------------------------------
$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Compilación --------------------------------------------------------
$(DIROBJ)%.o: $(DIRSRC)%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza de temporales ---------------------------------------------
clean:
	rm -f *.log $(EXEC) *~ $(DIRSRC)*~ $(DIRHEA)*~ 
	rm -rf $(DIROBJ)
