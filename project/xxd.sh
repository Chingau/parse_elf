#!/bin/sh

# $1：输入文件
# $2: 文件内的起始字节
# $3: 连续查看的字节数
xxd -u -a -g 1 -s $2 -l $3 $1
