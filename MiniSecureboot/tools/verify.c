#include <stdio.h>
#include "../common/file_io.h"
#include "../crypto/sb_crypto.h"
#include <stdlib.h>

int main(int argc, char *argv[]){

    uint8_t public_key[PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES];
    uint8_t signature[PQCLEAN_MLDSA87_CLEAN_CRYPTO_BYTES];

    if(argc!=3){
        printf("error; missing input file\n");
        printf("Usage: %s <firmware.bin> <signature.sig>\n", argv[0]);
        return -1;
     }
    const char *bl2_bin_path= argv[1];
    const char *bl2_sign_path= argv[2];
    const char *pub_keypath="keys/root_public.key";

    
    

    size_t bin_size=sb_get_file_size(bl2_bin_path);

    uint8_t *bl2_fw=malloc(bin_size);

    if (bl2_fw==NULL ){
        printf("Memort allocation failed\n");
        return -1;
    }

    
    
    

    if (sb_read_file(bl2_bin_path,bl2_fw,bin_size) != 0)
    {
        free(bl2_fw);
        return -1;
    }

    if (sb_read_file(bl2_sign_path, signature, PQCLEAN_MLDSA87_CLEAN_CRYPTO_BYTES)!=0){
        free(bl2_fw);
        return -1;
    };

    if(sb_read_file(pub_keypath, public_key, PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES)!=0){
        free(bl2_fw);
        return -1;
    };

    int verify_status=sb_verify(bl2_fw, bin_size,public_key, signature,PQCLEAN_MLDSA87_CLEAN_CRYPTO_BYTES);
    if(verify_status==0){
        printf("verifcation successful\n");
    }
    else{
        printf("verifcation failed\n");
        return -1;
    }
    free(bl2_fw);

}