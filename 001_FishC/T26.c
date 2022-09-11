#include <stdio.h>
#include <string.h>

// 结构体定义
struct Book {
    char title[128];
    char author[128];
    int price;
};

// 内存对齐
// 因为内存对齐，可以通过修改结构体的变量顺序，有效降低结构体占用内存
struct Demo {
    // 总计占用12字节
    char flag; // char 本身占用1字节；但内存对齐，占用4字节
    int index; // int 本身占用4字节
    char tag; // char 本身占用1字节；但内存对齐，占用4字节
};

struct Demo2 {
    // 总计占用8字节
    // char 本身占用1字节；但内存对齐，两个char连在一起，共占用4字节
    char flag;
    char tag;
    int index; // int 本身占用4字节
};

// 结构体嵌套
struct BookStore {
    char name[128];
    struct Book book;
};

// 结构体
int main() {
    // 使用结构体
    struct Book book;
    strcpy(book.title, "Clion");
    strcpy(book.author, "JetBrains");
    book.price = 50;
    printf("book:%s - %s - %d\n", book.title, book.author, book.price);

    // 初始化结构体
    struct Book book2 = {
            "IDEA",
            "JetBrains",
            20
    };
    printf("book2:%s - %s - %d\n", book2.title, book2.author, book2.price);

    // 内存对齐
    struct Demo demo = {'x', 100, 'x'};
    printf("size of Demo:%d\n", sizeof(demo)); // 12
    struct Demo2 demo2 = {'x', 'x', 100};
    printf("size of Demo2:%d\n", sizeof(demo2)); // 8

    // 结构体嵌套
    struct BookStore bookStore = {
            "BookStore",
            {"PyCharm", "JetBrains", 20}
    };
    printf("BookStore:%s - %s - %s - %d\n",
           bookStore.name, bookStore.book.title,
           bookStore.book.author, bookStore.book.price);

    // 结构体指针
    struct Book *mybook;
    mybook = &book;
    printf("(*mybook):%s - %s - %d\n",
           (*mybook).title, (*mybook).author, (*mybook).price);
    printf("mybook->:%s - %s - %d\n",
           mybook->title, mybook->author, mybook->price);

    // 结构体占用空间VS结构体指针占用空间
    struct BookStore *pBookStore = &bookStore;
    // 当需要结构体作为参数传递时，优先传递结构体指针，能有效降低内存占用空间
    printf("size of bookStore:%d\n", sizeof(bookStore)); // 388
    printf("size of pBookStore:%d\n", sizeof(pBookStore)); // 8
    return 0;
}
