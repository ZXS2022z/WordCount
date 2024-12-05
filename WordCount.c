#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(FILE *file);
int countWords(FILE *file);

//online change
int main(int argc, char *argv[]) {
    // ����������
    if (argc < 3) {
        printf("ʹ��: %s [-c|-w] [input_file_name]\n", argv[0]);
        return 1;
    }

    // ���ļ�
    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("����:�޷����ļ���\n");
        return 1;
    }

    int count;
    // ���ݲ���ѡ����
    if (strcmp(argv[1], "-c") == 0) {
        count = countCharacters(file);
        printf("�ַ�����%d\n", count);
    } else if (strcmp(argv[1], "-w") == 0) {
        count = countWords(file);
        printf("��������%d\n", count);
    } else {
        printf("����:��Ч������\n");
        return 1;
    }

    // �ر��ļ�
    fclose(file);
    return 0;
}

// ͳ���ַ���
int countCharacters(FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

// ͳ�Ƶ�����
int countWords(FILE *file) {
    int count = 0;
    char word[5000]; 
    while (fscanf(file, "%s", word) != EOF) {
        count++;
    }
    return count;
}

