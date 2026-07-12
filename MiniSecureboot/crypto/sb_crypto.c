
#include <stdint.h>

#include "api.h"
#include "sb_crypto.h"

int sb_generate_keypair(uint8_t *public_key, uint8_t *secret_key) {
  return PQCLEAN_MLDSA87_CLEAN_crypto_sign_keypair(public_key, secret_key);
}

int sb_sign(const uint8_t *message, size_t message_len,
            const uint8_t *secret_key, uint8_t *signature,
            size_t *signature_len) {

  return PQCLEAN_MLDSA87_CLEAN_crypto_sign_signature(signature, signature_len,
                                                     (const uint8_t *)message,
                                                     message_len, secret_key);
}

int sb_verify(const uint8_t *message, size_t message_len,
              const uint8_t *public_key, const uint8_t *signature,
              size_t signature_len) {
  return PQCLEAN_MLDSA87_CLEAN_crypto_sign_verify(signature, signature_len,
                                                  (const uint8_t *)message,
                                                  message_len, public_key);
}