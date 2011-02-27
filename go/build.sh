#!/bin/sh

CMP="6g"
LNK="6l"
BINNAME="hello.go.bin"

build() {
    $CMP my_package.go
    $CMP hello.go

    #no need link my_package
    $LNK -o $BINNAME hello.6
}

clean() {
    rm -f *.6
    rm -f 6.out
    rm -f $BINNAME
}

case "$1" in
    'build')
        build
        ;;
    'clean')
        clean
        ;;
    *)
        echo "usage $0 build|clean <--defaulting to 'build'"
        build
esac
