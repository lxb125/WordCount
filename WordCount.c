#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
	FILE *fp;
	int cnt = 0; // 统计个数
	if ((fp = fopen(argv[2], "r")) == NULL) {
		puts("error!\n");
		return 0;
	}
	if (argv[1][1] == 'w') { // 统计文件中单词的个数
		char s[1024];
		while (fscanf(fp, "%s", s) != EOF) {
			cnt ++;
			for (int i = 1; i < strlen(s) - 1; i ++)
				if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',')
					cnt ++;
		}
		printf("单词数=%d\n", cnt);
	} else if (argv[1][1] == 'c') { // 统计文件中字符的个数
		char c;
		while ((c = fgetc(fp)) != EOF)
			cnt ++;
		printf("字符数=%d", cnt);
	}
	fclose(fp);
	return 0;
}

