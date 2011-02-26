#!/bin/sh

CMP="6g"
LNK="6l"

MAIN=antfilter

$CMP ${MAIN}.go
$LNK ${MAIN}.6
