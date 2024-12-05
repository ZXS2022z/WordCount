#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(FILE *file);
int countWords(FILE *file);

//online change
int main(int argc, char *argv[]) {
    // 检查参数数量
    if (argc < 3) {
        printf("使用: %s [-c|-w] [input_file_name]\n", argv[0]);
        return 1;
    }

    // 打开文件
    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("错误:无法打开文件。\n");
        return 1;
    }

    int count;
    // 根据参数选择功能
    if (strcmp(argv[1], "-c") == 0) {
        count = countCharacters(file);
        printf("字符数：%d\n", count);
    } else if (strcmp(argv[1], "-w") == 0) {
        count = countWords(file);
        printf("单词数：%d\n", count);
    } else {
        printf("错误:无效参数。\n");
        return 1;
    }

    // 关闭文件
    fclose(file);
    return 0;
}

// 统计字符数
int countCharacters(FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

// 统计单词数
int countWords(FILE *file) {
    int count = 0;
    char word[5000]; 
    while (fscanf(file, "%s", word) != EOF) {
        count++;
    }
    return count;
}

