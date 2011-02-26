package main

import (
    //"os"
    "flag"  // command line option parser
	"fmt"
)

func main() {

	flag.Parse()   // Scans the arg list and sets up flags

	fmt.Printf("start...\n")

	//var s string = ""

	for i := 0; i < flag.NArg(); i++ {
        //os.Stdout.WriteString(s)
		fmt.Printf(flag.Arg(i) + "\n")
	}
}


