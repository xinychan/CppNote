#include <stdio.h>
#include <stdlib.h>

// 打开和关闭文件
int main() {
    FILE *fp1;
    FILE *fp2;
    int ch;
    if ((fp1 = fopen("hello.txt", "r")) == NULL) {
        printf("open fail hello");
        exit(0);
    }
    if ((fp2 = fopen("helloclion.txt", "w")) == NULL) {
        printf("open fail helloclion");
        exit(0);
    }
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
