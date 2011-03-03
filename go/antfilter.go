package main

import (
	"os"
	"flag"
	"fmt"
	//"./file"
	"./filter"
)

// flags / options / usage
var (
	fHelp *bool = flag.Bool("h", false, "this message")
	fDebug *bool = flag.Bool("D", false, "echo debug info")
	fFilterFile *string = flag.String("f", "", "filter file")
)
var Usage = func() {
    fmt.Fprintf(os.Stderr, "usage of %s:\n", os.Args[0])
    flag.PrintDefaults() //this is what happens by default w/o a Usage()
}

func main() {
	flag.Parse()

	if *fHelp {
		Usage()
		return
	}

	if *fFilterFile == "" {
		fmt.Fprintln(os.Stderr, "fatal; please specify -f for filter-file")
		return
	}

	if *fDebug {
		fmt.Printf("*fFilterFile: %v\n", *fFilterFile)
		for i := 0; i < flag.NArg(); i++ {
			fmt.Printf("file %v: %v\n", i, flag.Arg(i))
		}
	}


	flt, err := filter.NewFilter(*fFilterFile)
	if err == nil {
		fmt.Printf("flt.Filename:%v\n", flt.Filename)
	} else {
		fmt.Fprintf(os.Stderr, "error reading filter file: %v\n", err)
		//return exit?
	}





}


