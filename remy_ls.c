/*************************************************************************
	> File Name: remy_ls.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月08日 星期三 09时53分26秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_LENGTH 256
#define LS 0
#define LS_AL 1

int cmp_filename(const void *a, const void *b){
    char *s1 = (char *)a;
    char *s2 = (char *)b;
    return strcmp(s1, s2);
}

void file_info(struct stat *buf, char *filename) {
    
    struct passwd *pw = getpwuid(buf->st_uid);
    struct group *gp = getgrgid(buf->st_gid);
    char timebuf[MAX_LENGTH] = {0};

    if(S_ISREG(buf->st_mode))
        putchar('-');
    else if(S_ISDIR(buf->st_mode))
        putchar('d');
    else if(S_ISCHR(buf->st_mode))
        putchar('c');
    else if(S_ISBLK(buf->st_mode))
        putchar('b');
    else if(S_ISFIFO(buf->st_mode))
        putchar('f');
    else if(S_ISLNK(buf->st_mode))
        putchar('l');
    else if(S_ISSOCK(buf->st_mode))
        putchar('s');
    else
        putchar('?');
    
    // 用户权限
    printf(buf->st_mode & S_IRUSR ? "r":"-");
    printf(buf->st_mode & S_IWUSR ? "w":"-");
    printf(buf->st_mode & S_IXUSR ? "x":"-");

    // 组权限
    printf(buf->st_mode & S_IRGRP ? "r":"-");
    printf(buf->st_mode & S_IWGRP ? "w":"-");
    printf(buf->st_mode & S_IXGRP ? "x":"-");

    // 其它权限
    printf(buf->st_mode & S_IROTH ? "r":"-");
    printf(buf->st_mode & S_IWOTH ? "w":"-");
    printf(buf->st_mode & S_IXOTH ? "x":"-");

    printf("\t");
    
    printf("%d\t", buf->st_nlink);

    printf("%s\t", pw->pw_name);

    printf("%s\t", gp->gr_name);

    printf("%d\t", (int)(buf->st_size));
    
    ctime_r(&(buf->st_mtime), timebuf);
    if(timebuf[0] != 0)
        timebuf[strlen(timebuf)-1] = 0; /*去掉'\n'*/
    printf("%-20.20s\t", timebuf);

}


void print_filename(char *filename) {
    printf("%s\n", filename);
}

void show_info(char *pathname) {
    int m, n;
    struct stat *buf;
    char filename[MAX_LENGTH];
    //从路径中截取文件名,参考了linuxC编程实战一书
    for (m = 0, n = 0; m < strlen(pathname); m++) {
        if (pathname[m] == '/') {
            n = 0;
            continue;
        }
        filename[n++] = pathname[m];
    }
    filename[n] = '\0';
    //上面循环结束后只能保存下来最后一个/后面的字符串，即我们所要的文件名
    
    if (stat(pathname, buf) == -1) {
		perror("stat");
	}
    
    file_info(buf, filename);
    printf(" %d\n", filename);
/*    switch (sign) {
        case LS:
            print_filename(filename);
            break;
        
        case LS_AL:
            file_info(buf, filename);
            printf(" %s\n", filename);
            break;
        
        default:
            break;
    }
*/
}

void dir_info(char *dirname) {
    DIR *dir = NULL;
    struct dirent *dp;
    int count = 0;
    char sort_filenames[MAX_LENGTH][MAX_LENGTH];

    //先获取文件总数
    dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
    }
    
    while ((dp = readdir(dir)) != NULL) {
        count++;
    }
    closedir(dir);
    
    int len = strlen(dirname);

    for (int i = 0; i < count; i++) {
        dp = readdir(dir);
        if (dp == NULL) {
            perror("readdir");
        }
        strncpy(sort_filenames[i], dirname, len);
        sort_filenames[i][len] = '\0';
        strcat(sort_filenames[i], dp->d_name);
        sort_filenames[i][len + strlen(dp->d_name)] = '\0';
    }
    //排序
   // qsort(sort_filenames, count, MAX_LENGTH, cmp_filename);
    for (int i = 0; i < count; i++) {
        show_info(sort_filenames[i]);
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    struct stat *buf = malloc(sizeof(struct stat));  
    char *pathname;
    if (argc == 1) {
        pathname = ".";
        dir_info(pathname);
    } else{
        for (int i = 1; i < argc; i++) {
            stat(argv[i], buf);
            if(S_IFDIR & buf->st_mode){ 
                pathname = argv[i];
                dir_info(pathname);
                if (i < argc - 1) printf("\n");
            }
            else {
                printf("Not files or directories!\n");
            }
        }
    }
    return 0;
}

