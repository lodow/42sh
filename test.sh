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

COMMAND="env env env env env env ls && env env env ls && env ls && ls && env env env env env env env env env env env env `echo ls` && ls && env env env env env env env env env env env env env env env ls"
check_diff | less

rm -f ${OUT} ${OUTB}


