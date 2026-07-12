
CC=gcc


INCLUDE= \
-I ../PQClean/crypto_sign/ml-dsa-87/clean \
-I ../PQClean/common \
-I crypto \
-I common \
-I bootrom


COMMON_SRC= \
../PQClean/common/*.c \
common/*.c \
../PQClean/crypto_sign/ml-dsa-87/clean/*.c \
crypto/*.c \

all: keygen sign verify bl1

keygen:
	$(CC) $(INCLUDE) tools/keygen.c	$(COMMON_SRC) -o tools/keygen

sign: 
	$(CC) $(INCLUDE) tools/sign.c $(COMMON_SRC)	-o tools/signgen

verify: 
	$(CC) $(INCLUDE) tools/verify.c $(COMMON_SRC) -o tools/verify

bl1: 
	$(CC) $(INCLUDE) bootrom/main.c	bootrom/boot.c $(COMMON_SRC) -o bootrom/bl1

clean: 
	rm -f tools/keygen tools/signgen bootrom/bl1

