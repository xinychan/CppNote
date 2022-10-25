#include "include/io_utils.h"
#include <string.h>
#include <stdlib.h>

// C99 的 restrict
int main() {
    // C99 新增 restrict 表示参数指向的内存不允许重叠

    // _Dst 和 _Src 两个指针允许重叠
    // void *__cdecl memmove(void *_Dst,const void *_Src,size_t _Size
    // memmove();

    //  _Dst 和 _Src 两个指针不允许重叠
    // void * __cdecl memcpy(void * __restrict__ _Dst,const void * __restrict__ _Src,size_t _Size)
    // memcpy();
    return 0;
}
