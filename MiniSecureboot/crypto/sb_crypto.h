#ifndef SB_CRYPTO_H
#define SB_CRYPTO_H

#include <stddef.h>
#include <stdint.h>

#define PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES 2592
#define PQCLEAN_MLDSA87_CLEAN_CRYPTO_SECRETKEYBYTES 4896
#define PQCLEAN_MLDSA87_CLEAN_CRYPTO_BYTES 4627

int sb_generate_keypair(uint8_t *public_key, uint8_t *secret_key);

int sb_sign(const uint8_t *message, size_t message_len,
            const uint8_t *secret_key, uint8_t *signature,
            size_t *signature_len);

int sb_verify(const uint8_t *message, size_t message_len,
              const uint8_t *public_key, const uint8_t *signature,
              size_t signature_len);

#endif