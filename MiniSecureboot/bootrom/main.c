#include <stdio.h>
#include "../common/file_io.h"
#include "../crypto/sb_crypto.h"
#include <stdlib.h>
#include "boot.h"

int main(){

    boot_verify_bl2();
    return 0;

}