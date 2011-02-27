#!/bin/sh

CMP="6g"
LNK="6l"


build() {
    $CMP my_package.go
    $CMP hello.go

    $LNK hello.6 #no need link my_package
}

clean() {
    rm *.6
    rm 6.out
}

case "$1" in
    'build')
        build
        ;;
    'clean')
        clean
        ;;
    *)
        echo "usage $0 build|clean"
esac
