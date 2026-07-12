#include <stdio.h>
#include "../common/file_io.h"
#include "../crypto/sb_crypto.h"
#include <stdlib.h>
#include "../common/path.h"

int sb_jump_to_bl2(const char *path){
    
    printf("[BL1] Jumping to BL2...\n");
    system(path);
    return 0;
}

int boot_verify_bl2(){
    uint8_t public_key[PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES];
    uint8_t signature[PQCLEAN_MLDSA87_CLEAN_CRYPTO_BYTES];

  

    
    

    size_t bin_size=sb_get_file_size(BL2_PATH);

    uint8_t *bl2_fw=malloc(bin_size);

    if (bl2_fw==NULL ){
        printf("Memort allocation failed\n");
        return -1;
    }

    
    
    

    if (sb_read_file(BL2_PATH,bl2_fw,bin_size) != 0)
    {
        free(bl2_fw);
        return -1;
    }

    if (sb_read_file(BL2_SIGNATURE_PATH, signature, PQCLEAN_MLDSA87_CLEAN_CRYPTO_BYTES)!=0){
        free(bl2_fw);
        return -1;
    };

    if(sb_read_file(ROOT_PUBLIC_KEY_PATH, public_key, PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES)!=0){
        free(bl2_fw);
        return -1;
    };

    int verify_status=sb_verify(bl2_fw, bin_size,public_key, signature,PQCLEAN_MLDSA87_CLEAN_CRYPTO_BYTES);
    
    if(verify_status==0){
                printf("[BL1] BL2 signature verification PASSED\n");
                sb_jump_to_bl2(BL2_PATH);
            }
    else{
        printf("[BL1] BL2 signature verification FAILED\n");
        printf("[BL1] Boot halted.\n");
        return -1;
    }
    free(bl2_fw);
    return 0;
}