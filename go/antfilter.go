package main

import (
	"os"
	"flag"
	"fmt"
	//"./file"
	"./filter"
	"io/ioutil" //contents, err := ioutil.ReadFile(fn)
	"strings"
	"./log"
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

	filterFile, err := ioutil.ReadFile(*fFilterFile)
	if err == nil {
		fmt.Printf("filterFile:\n%s\n", filterFile)
	} else {
		fmt.Fprintf(os.Stderr, "err: %v\n", err)
		os.Exit(1);
	}

	filterMap := map[string] string{}
	//var filterMap map[string] string

	//filterMap["asd"] = "123"

	fmt.Printf("filterMap: %v\n", filterMap)


	lines := strings.Split(string(filterFile), "\n", -1)

	fmt.Printf("len-lines: %v\n", len(lines))
	fmt.Printf("lines: %v\n", lines)

	for _, l := range lines {
		//fmt.Printf("L[%v]\n", l)
		k, v := filter.ProcLine(l)
		fmt.Printf("k:%v v:%v\n", k, v)
	}

	log.Debug("asd")
}


