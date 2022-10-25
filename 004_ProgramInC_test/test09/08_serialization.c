#include <stdio.h>
#include "include/io_utils.h"
#include <errno.h>
#include <string.h>

#define ERROR 0
#define OK 1

// 需要序列化的结构体
typedef struct {
    int visibility;
    int allow_notification;
    int refresh_rate;
    int region;
    int font_size;
} Settings;

// 打印结构体信息
void PrintSettings(Settings *settings) {
    PRINT_INT(settings->visibility);
    PRINT_INT(settings->allow_notification);
    PRINT_INT(settings->refresh_rate);
    PRINT_INT(settings->region);
    PRINT_INT(settings->font_size);
}

// Settings 信息保存到文件
int SaveSettings(Settings *settings, char *settings_file) {
    // 二进制写入模式，打开文件
    FILE *file = fopen(settings_file, "wb");
    if (file) {
        // fwrite 写入 Settings 信息保存到文件
        fwrite(&settings->visibility, sizeof(settings->visibility), 1, file);
        fwrite(&settings->allow_notification, sizeof(settings->allow_notification), 1, file);
        fwrite(&settings->refresh_rate, sizeof(settings->refresh_rate), 1, file);
        fwrite(&settings->region, sizeof(settings->region), 1, file);
        fwrite(&settings->font_size, sizeof(settings->font_size), 1, file);
        // 关闭文件流
        fclose(file);
        return OK;
    } else {
        perror("Failed to save settings");
        return ERROR;
    }
}

// 从文件读取 Settings 信息
void LoadingSettings(Settings *settings, char *settings_file) {
    // 二进制读取模式，打开文件
    FILE *file = fopen(settings_file, "rb");
    if (file) {
        // fread 从文件读取信息，赋值给 Settings
        fread(&settings->visibility, sizeof(settings->visibility), 1, file);
        fread(&settings->allow_notification, sizeof(settings->allow_notification), 1, file);
        fread(&settings->refresh_rate, sizeof(settings->refresh_rate), 1, file);
        fread(&settings->region, sizeof(settings->region), 1, file);
        fread(&settings->font_size, sizeof(settings->font_size), 1, file);
        // 关闭文件流
        fclose(file);
    } else {
        settings->visibility = 1;
        settings->allow_notification = 1;
        settings->refresh_rate = 30;
        settings->region = 86;
        settings->font_size = 18;
    }
}

// Settings 信息保存到文件
int SaveSettings2(Settings *settings, char *settings_file) {
    // 二进制写入模式，打开文件
    FILE *file = fopen(settings_file, "wb");
    if (file) {
        // fwrite 写入 Settings 信息保存到文件；直接访问 Settings
        fwrite(settings, sizeof(Settings), 1, file);
        // 关闭文件流
        fclose(file);
        return OK;
    } else {
        perror("Failed to save settings");
        return ERROR;
    }
}

// 从文件读取 Settings 信息
void LoadingSettings2(Settings *settings, char *settings_file) {
    // 二进制读取模式，打开文件
    FILE *file = fopen(settings_file, "rb");
    if (file) {
        // fread 从文件读取信息，赋值给 Settings；直接访问 Settings
        fread(settings, sizeof(Settings), 1, file);
        // 关闭文件流
        fclose(file);
    } else {
        settings->visibility = 1;
        settings->allow_notification = 1;
        settings->refresh_rate = 30;
        settings->region = 86;
        settings->font_size = 18;
    }
}

// 序列化和反序列化的基本实现
int main() {
    Settings settings;
    // settings.bin 使用 BinEd 插件打开
    LoadingSettings2(&settings, "settings.bin");
    PrintSettings(&settings);
    settings.allow_notification = 16;
    settings.font_size = 32;
    SaveSettings2(&settings, "settings.bin");
    return 0;
}
