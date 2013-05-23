#!/bin/bash

SHB=/bin/bash
SH=./42SH
OUT=tmp
OUTB=tmp2

COMMAND=""

check_diff() {
 echo ${COMMAND} | ${SH} > ${OUT} 2>&1
 echo ${COMMAND} | ${SHB} > ${OUTB} 2>&1
 diff ${OUT} ${OUTB}
}

COMMAND="|"
check_diff | less

COMMAND=";"
check_diff | less

COMMAND="&"
check_diff | less

COMMAND="&&"
check_diff | less

COMMAND="||"
check_diff | less

COMMAND="\\"
check_diff | less

COMMAND="ls | | | ||||||||"
check_diff | less

COMMAND=";;;;;;;;ls;;;;;;;;;"
check_diff | less

COMMAND="\"\"\"\\\"\"\"\""
check_diff | less

COMMAND="ls | | | ||||||||"
check_diff | less

COMMAND="env env env env env env env -i env ls"
check_diff | less

COMMAND="cd /; cd -; cd /; cd ../; cd;"
check_diff | less

COMMAND="ls && dfe"
check_diff | less

COMMAND="ls ../ && ls"
check_diff | less

COMMAND="ls || ls ../"
check_diff | less

COMMAND="echo -n test"
check_diff | less

COMMAND="cd .. && ls"
check_diff | less

COMMAND="env | cat -e"
check_diff | less

COMMAND="ls | wc -l > toto; cat -e << abc | wc -l >> toto; cat -e toto"
check_diff | less

COMMAND="env env env env env env ls && env env env ls && env ls && ls && env env env env env env env env env env env env `echo ls` && ls && env env env env env env env env env env env env env env env ls"
check_diff | less

COMMAND=">>"
check_diff | less

COMMAND="cat >> |"
check_diff | less

COMMAND="test << >>"
check_diff | less

COMMAND="test &&"
check_diff | less

COMMAND="test ||"
check_diff | less

COMMAND="test || test && test && test || test ; ; ; ; ; ; ; ungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoustest || test && test && test || test ; ; ; ; ; ; ; ungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertous;"
check_diff | less

COMMAND="test | ;pwd"
check_diff | less

COMMAND="test | pwd ;"
check_diff | less

COMMAND="test 1=2 && ls"
check_diff | less

COMMAND="setenv TRUC toto ; echo ${TRUC} ; echo ${truc}; setenv TRUC titi ; echo ${TRUC} ; echo ${sdse}"
check_diff | less

COMMAND="ls > toto ; date >> toto ; >> toto ls ; < toto cat ;"
check_diff | less

COMMAND="<< toto cat > toto ; << EOF cat | sed s/toto/0/ > ma_note ; /bin/echo -n ma_note: ; ; < ma_note cat"
check_diff | less

COMMAND="cd ../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../ ; pwd ; cd -"
check_diff | less

COMMAND="unsetenv OLD_PWD ; unsetenv OLDPWD ; cd -"
check_diff | less

COMMAND="cat /etc/passwd | tr : # | tr -s abcdefghijklmnopqrstuvwxyz| cut -c 2 | grep -e a -e b -e\
 c -e d -e e -e f -e g -e h -e i -e j -e k -e l -e m -e n -e o -e p -e q -e r -e s -e \
t -e u -e v -e w -e x -e y -e z |sort|uniq -c"
check_diff | less

COMMAND="ls *c*"
check_diff | less

COMMAND="echo `ls`"
check_diff | less

COMMAND="echo `cat main.c | more` | more"
check_diff | less

COMMAND="ls /dev | grep tty | sort -r | rev > toto ; < toto cat | rev | wc -l > titi"
check_diff | less

rm -f ${OUT} ${OUTB}


