#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
	FILE *fp;
	int cnt = 0; // ͳ�Ƹ���
	if ((fp = fopen(argv[2], "r")) == NULL) {
		puts("error!\n");
		return 0;
	}
	if (argv[1][1] == 'w') { // ͳ���ļ��е��ʵĸ���
		char s[1024];
		while (fscanf(fp, "%s", s) != EOF) {
			cnt ++;
			for (int i = 1; i < strlen(s) - 1; i ++)
				if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',')
					cnt ++;
		}
		printf("������=%d\n", cnt);
	} else if (argv[1][1] == 'c') { // ͳ���ļ����ַ��ĸ���
		char c;
		while ((c = fgetc(fp)) != EOF)
			cnt ++;
		printf("�ַ���=%d", cnt);
	}
	fclose(fp);
	return 0;
}
