package main

import (
	"os"
	"flag"
	"fmt"
	"./filter"
	"io/ioutil" //contents, err := ioutil.ReadFile(fn)
	"strings"
	"./target"
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
	if err != nil {
		fmt.Fprintf(os.Stderr, "err: %v\n", err)
		os.Exit(1);
	}

	lines := strings.Split(string(filterFile), "\n", -1)

	filterMap := map[string] string{}

	for _, l := range lines {
		k, v, ret := filter.ProcLine(l)
		//fmt.Printf("k:%v v:%v b:%v\n", k, v, ret)

		if ret {
			filterMap[k] = v
		}
	}

	fmt.Printf("filterMap: %v\n", filterMap)

	// ----------

	// iterate thru the commandline files (to be filtered):
	for i := 0; i < flag.NArg(); i++ {
		fmt.Printf("filtering file %v: %v ...\n", i, flag.Arg(i))
		filtering, err := ioutil.ReadFile(flag.Arg(i))
		if err != nil {
			fmt.Fprintf(os.Stderr, "err: %v\n", err)
			os.Exit(1);
		}
		fmt.Printf("filtering: %s\n", filtering)


		//target.ReplaceToken("some.replace", "val...", &filtering)
		new_file := target.ReplaceTokens(&filtering, &filterMap)
		fmt.Printf("new_file: %s\n", new_file)

		//write back the file filtering to filename "i":
		err = ioutil.WriteFile(flag.Arg(i), *new_file, 0666)
		if err != nil {
			fmt.Fprintf(os.Stderr, "err: %v\n", err)
			os.Exit(1);
		}

	}

}


