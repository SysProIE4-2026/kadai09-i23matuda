/*
 *  myenv.c : env コマンドのクローン
 */
extern char **environ;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __linux__
#include "myputenv.h"
#endif

int main(int argc,char *argv[],char *envp[]){
  for(int i = 1;i<argc;i++){
    if(putenv(argv[i])==-1){
      if(execvp(argv[i],&argv[i])==-1){
        perror(argv[i]);
        exit(1);
      }
    }
  }
  for(int i = 0;environ[i] != NULL;i++){
        printf("%s\n",environ[i]);
  }
}
/* 実行例
 % ./myenv
TMPDIR=/var/folders/xf/0919rxvn2z7b0ffn3w2x4x7h0000gn/T/
__CFBundleIdentifier=com.apple.Terminal
XPC_FLAGS=0x0
TERM=xterm-256color
SSH_AUTH_SOCK=/var/run/com.apple.launchd.8LCKu1uDDl/Listeners
XPC_SERVICE_NAME=0
TERM_PROGRAM=Apple_Terminal
COLORTERM=truecolor
OSLogRateLimit=64
TERM_PROGRAM_VERSION=470.2
TERM_SESSION_ID=78B0CF6A-C7DB-47D4-9104-9A4E5F8F60B3
SHELL=/bin/zsh
HOME=/Users/matudamisaki
LOGNAME=matudamisaki
USER=matudamisaki
PATH=/opt/homebrew/opt/openjdk/bin:/opt/homebrew/bin:/opt/homebrew/
sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/
sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/
usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/
bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/
bootstrap/usr/appleinternal/bin:/pkg/env/global/bin
SHLVL=1
PWD=/Users/matudamisaki/OneDrive - 独立行政法人 国立高等専門学校機構/Syspro/
kadai09-i23matuda
OLDPWD=/Users/matudamisaki/OneDrive - 独立行政法人 国立高等専門学校機構/Syspro
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
FPATH=/opt/homebrew/share/zsh/site-functions:/usr/local/share/
zsh/site-functions:/usr/share/zsh/site-functions:/usr/share/zsh/5.9/functions
INFOPATH=/opt/homebrew/share/info:
CPPFLAGS=-I/opt/homebrew/opt/openjdk/include
LANG=ja_JP.UTF-8
_=/Users/matudamisaki/OneDrive - 烫?竃?胁??惴?泃?人 僻?竃?髃?筃?専郶?学惀??橃?槃?/
Syspro/kadai09-i23matuda/./myenv

以下から省略と書かれている場合上記の実行例が入るものとする

% ./myenv ABC=abc 
ABC=abc

 % ./myenv
 省略
 再度実行した場合、環境変数ABCはリストになかった

% ./myenv ABC=abc DEF=def
省略
ABC=abc
DEF=def

% ./myenv  ls       
Makefile	myenv.c		myputenv.h	README.pdf
myenv		myputenv.c	README.md

% ./myenv ABC=abc ls
Makefile	myenv.c		myputenv.h	README.pdf
myenv		myputenv.c	README.md

 % ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba ls -l
total 384
-rw-r--r--  1 matudamisaki  staff     132  6月 29 21:36 Makefile
-rwxr-xr-x  1 matudamisaki  staff   33784  6月 30 21:39 myenv
-rw-r--r--@ 1 matudamisaki  staff    2452  6月 30 21:39 myenv.c
-rwxr-xr-x@ 1 matudamisaki  staff     216  6月 29 21:36 myputenv.c
-rw-r--r--  1 matudamisaki  staff      93  6月 29 21:36 myputenv.h
-rw-r--r--  1 matudamisaki  staff    1268  6月 29 21:36 README.md
-rw-r--r--@ 1 matudamisaki  staff  139098  6月 29 21:36 README.pdf

% ./myenv a          
a: No such file or directory

% ./myenv a ls       
a: No such file or directory

% ./myenv ls a       
ls: a: No such file or directory

*/
