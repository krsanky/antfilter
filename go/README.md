~~~

hg clone -r release https://go.googlecode.com/hg/ go

~~~

$GOBIN
    The location where binaries will be installed. The default is $GOROOT/bin

~~~

export GOROOT=$HOME/go
export GOARCH=386
export GOOS=linux

~~~

To build the Go distribution, run


~~~

$ cd go/src
$ ./all.bash

~~~


#######################################
Writing programs:

Given a file file.go, compile it using

$ 6g file.go

6g is the Go compiler for amd64; it will write the output in file.6. The
\u20186\u2019 identifies files for the amd64 architecture. The identifier
letters for 386 and arm are \u20188\u2019 and \u20185\u2019. That is,
if you were compiling for 386, you would use 8g and the output would be
named file.8.

To link the file, use

$ 6l file.6

and to run it

$ ./6.out

A complete example:

$ cat >hello.go <<EOF
package main

import "fmt"

func main() {
     fmt.Printf("hello, world\n")
}
EOF
$ 6g hello.go
$ 6l hello.6
$ ./6.out
hello, world
$

There is no need to list hello.6's package dependencies (in this case,
package fmt) on the 6l command line. The linker learns about them by
reading hello.6.

To build more complicated programs, you will probably want to use a
Makefile. There are examples in places like go/src/cmd/godoc/Makefile and
go/src/pkg/*/Makefile. The document about contributing to the Go project
gives more detail about the process of building and testing Go programs.

