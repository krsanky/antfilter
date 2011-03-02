package main

import (
	"os"
	"flag"
	"fmt"
	//"./file"
)

var (
	fHelp *bool = flag.Bool("h", false, "this message")
	fDebug *bool = flag.Bool("D", false, "echo debug info")
	fFilterFile *string = flag.String("f", "", "filter file")
)
var Usage = func() {
    fmt.Fprintf(os.Stderr, "Usage of %s:\n", os.Args[0])
	//antfilter [-h][-f <filter-file>][-D] <files-to-filte
    flag.PrintDefaults()
}

func main() {
	flag.Parse()

	if *fHelp {
		//flag.PrintDefaults()
		Usage()
		return
	}

	if *fFilterFile == "" {
		fmt.Fprintln(os.Stderr, "fatal; please specify -f for filter-file")
		return
	}

	for i := 0; i < flag.NArg(); i++ {
		fmt.Printf(flag.Arg(i) + "\n")
	}

	//file.Read()
}


