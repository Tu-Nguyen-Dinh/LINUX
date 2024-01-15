.PHONY: all clean
LIB_NAME_SHARE := share
LIB_NAME_STATIC := static
CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
OBJS_DIR := $(CUR_DIR)/objs
OBJ_SHARE := $(OBJS_DIR)/share
OBJ_STATIC := $(OBJS_DIR)/static

INC_DIR := $(CUR_DIR)/inc

SRC_DIR := $(CUR_DIR)/src
LIB_DIR := $(CUR_DIR)/lib
LIB_STATIC := $(LIB_DIR)/static
LIB_SHARED := $(LIB_DIR)/shared

INC_FLAG := -I $(INC_DIR)
CC := gcc 
mk_obj_main:
	$(CC) -c  $(CUR_DIR)/main.c -o  $(OBJS_DIR)/main.o  $(INC_FLAG)
mk_obj_share:
	
	$(CC) -c -fPIC $(SRC_DIR)/hello.c -o  $(OBJ_SHARE)/hello.o  $(INC_FLAG)
	$(CC) -c -fPIC $(SRC_DIR)/math.c -o  $(OBJ_SHARE)/math.o  $(INC_FLAG)
mk_obj_static:
	$(CC) -c $(SRC_DIR)/hello.c -o  $(OBJ_STATIC)/hello.o  $(INC_FLAG)
	$(CC) -c $(SRC_DIR)/math.c -o  $(OBJ_STATIC)/math.o  $(INC_FLAG)
mk_lib_share:
	$(CC) -shared $(OBJ_SHARE)/hello.o $(OBJ_SHARE)/math.o -o $(LIB_SHARED)/lib$(LIB_NAME_SHARE).so
mk_lib_static:
	ar rcs $(LIB_STATIC)/lib$(LIB_NAME_STATIC).a $(OBJ_STATIC)/hello.o $(OBJ_STATIC)/math.o
install_share: 
	cp -f $(LIB_SHARED)/lib$(LIB_NAME_SHARE).so /usr/lib
install_static:
	cp -f $(LIB_STATIC)/lib$(LIB_NAME_STATIC).a /usr/lib
linking_share:
	$(CC) $(OBJS_DIR)/main.o -L$(LIB_SHARED) -l$(LIB_NAME_SHARE) -o $(BIN_DIR)/use-shared-lib
linking_static:
	$(CC) $(OBJS_DIR)/main.o -L$(LIB_STATIC) -l$(LIB_NAME_STATIC) -o $(BIN_DIR)/use-static-lib

clean:

	rm -rf $(OBJ_SHARE)
	rm -rf $(OBJ_STATIC)
	rm -rf $(BIN_DIR)/*
	rm -rf $(LIB_SHARED)/lib$(LIB_NAME_STATIC).so
	rm -rf $(LIB_NAME_STATIC)/lib$(LIB_NAME_STATIC).a
	rm -rf /usr/lib/lib$(LIB_NAME_STATIC).a
	rm -rf /usr/lib/lib$(LIB_NAME_SHARE).so
	rm -rf $(LIB_SHARED)/*
	rm -rf $(LIB_STATIC)/*

