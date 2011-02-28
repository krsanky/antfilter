package main

import (
    "flag"  // command line option parser
	"fmt"
	"./file"
)

func main() {

	flag.Parse()   // Scans the arg list and sets up flags

	fmt.Printf("start...\n")

	for i := 0; i < flag.NArg(); i++ {
        //os.Stdout.WriteString(s)
		fmt.Printf(flag.Arg(i) + "\n")
	}

	file.Read()
}


