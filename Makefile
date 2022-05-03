CC = gcc
PROGRAM = cgrad
VERSION = 0.1.0

.PHONY: all clean

VEC = src/vec
VEC_I32_C = $(VEC)/vec_i32.c

MATR = src/matrix
MATR_I32_C = $(MATR)/matrix_i32.c

LINALG_O = vec_i32.o matrix_i32.o
LINALG_I32_C = $(MATR_I32_C) $(VEC_I32_C)

LAYERS = src/layers
STACK_VEC_I32_C = $(LAYERS)/stack_vec_i32.c

LIN_I32_C = $(LAYERS)/lin_i32.c


all: lin_i32.o

clean:
	rm *.o *.out

vec_i32.o:
	$(CC) -c $(VEC)/vec_i32.c

test_vec_i32.o:
	$(CC) -c $(VEC)/tests/test_vec_i32.c $(VEC)/vec_i32.c

test_vec.out: test_vec_i32.o
	$(CC) test_vec_i32.o vec_i32.o $(VEC)/tests/test_vec.c

matrix_i32.o:
	$(CC) -c $(MATR)/matrix_i32.c $(VEC_I32_C)

test_matrix_i32.o:
	$(CC) -c $(MATR)/tests/test_matrix_i32.c $(MATR_I32_C) $(VEC_I32_C)

test_matrix.out: test_matrix_i32.o
	$(CC) $(MATR)/tests/test_matrix.c test_matrix_i32.o $(LINALG_O)

stack_vec_i32.o:
	$(CC) -c $(STAC_VEC_I32_C) $(VEC_I32_C)

test_stack_vec_i32.o:
	$(CC) -c $(LAYERS)/tests/test_stack_vec_i32.c $(STACK_VEC_I32_C) $(VEC_I32_C)

test_stack.out: test_stack_vec_i32.o
	$(CC) $(LAYERS)/tests/test_stack.c test_stack_vec_i32.o stack_vec_i32.o vec_i32.o

lin_i32.o:
	$(CC) -c $(LIN_I32_C) $(STACK_VEC_I32_C) $(MATR_I32_C) $(VEC_I32_C)

test_lin_i32.o:
	$(CC) -c $(LAYERS)/tests/test_lin_i32.c $(LIN_I32_C) $(STACK_VEC_I32_C) $(LINALG_I32_C)

test_lin.out: test_lin_i32.o
	$(CC) $(LAYERS)/tests/test_lin.c *.o

libcgrad.a: all
	ar rcs libcgrad.a *.o

