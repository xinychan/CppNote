#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"
#include "include/time_utils.h"

// 下载任务参数
typedef struct Context {
    // 线程锁
    mtx_t mutex;
    // 剩余下载任务
    int download_left;
} Context;

// 下载请求
typedef struct DownloadRequest {
    Context *context;
    // 下载地址
    char const *url;
    // 下载文件名称
    char const *filename;
    // 下载进度
    int progress;
    // 下载时间间隔参数
    int interval;

    // 下载完成回调函数
    void (*callback)(struct DownloadRequest *);
} DownloadRequest;

// 下载完成回调函数
void DownloadCallback(DownloadRequest *request) {
    // 线程加锁
    mtx_lock(&request->context->mutex);
    // 完成一个下载任务，剩余下载任务-1
    request->context->download_left--;
    // 打印下载信息
    PRINTLNF("\rDownload file from: %s into %s successfully, left: %d",
             request->url,
             request->filename,
             request->context->download_left);
    // 线程释放锁
    mtx_unlock(&request->context->mutex);
}

// 下载文件
int DownloadFile(DownloadRequest *request) {
    // 开始下载，打印数据信息
    PRINTLNF("\rDownloading file from: %s into %s ...", request->url, request->filename);
    // 模拟下载进度
    for (int i = 0; i < 101; ++i) {
        request->progress = i;
        // Sleep 模拟下载耗时
        SleepMs(request->interval);
    }
    // 下载完成，执行回调函数
    request->callback(request);
    return 0;
}

// 下载任务数目
#define DOWNLOAD_TASKS 5

// 并发任务执行与函数回调
int main(void) {
    char *urls[] = {
            "https://www.test.com/file1",
            "https://www.test.com/file2",
            "https://www.test.com/file3",
            "https://www.test.com/file4",
            "https://www.test.com/file5",
    };
    char *filenames[] = {
            "download/file1",
            "download/file2",
            "download/file3",
            "download/file4",
            "download/file5",
    };

    // 下载请求数组；初始化下载请求数组，开辟下载请求内存空间
    DownloadRequest requests[DOWNLOAD_TASKS];
    // 下载任务参数
    Context context = {.download_left = DOWNLOAD_TASKS};
    // 初始化锁
    mtx_init(&context.mutex, mtx_plain);

    for (int i = 0; i < DOWNLOAD_TASKS; ++i) {
        // 初始化下载请求内容
        requests[i].context = &context;
        requests[i].url = urls[i];
        requests[i].filename = filenames[i];
        requests[i].progress = 0;
        requests[i].interval = i * 50 + 100;
        requests[i].callback = DownloadCallback;
        // 创建线程，开始执行下载请求
        thrd_t thrd;
        // 执行下载请求
        thrd_create(&thrd, DownloadFile, &requests[i]);
        // 调用 thrd_detach 后线程会释放资源，不关注线程执行结果
        thrd_detach(thrd);
    }

    // 获取下载进度信息
    while (1) {
        mtx_lock(&context.mutex);
        // 加锁获取剩余下载任务，获取后释放锁
        int download_left = context.download_left;
        mtx_unlock(&context.mutex);
        // 没有剩余下载任务，则下载完成
        if (download_left == 0) {
            break;
        }
        // 光标回到行首
        printf("\r");
        // 更新下载进度
        for (int i = 0; i < DOWNLOAD_TASKS; ++i) {
            printf("%s -- %3d%% \t", requests[i].filename, requests[i].progress);
        }
        fflush(stdout);
        // 每100毫秒刷新下载进度
        SleepMs(100);
    }

    // 销毁锁
    mtx_destroy(&context.mutex);
    return 0;
}