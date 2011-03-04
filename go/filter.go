package filter

import (
	"os"
	"io/ioutil"
	"fmt"
)

type Filter struct {
	Filename string
	contents string
}

func NewFilter(fn string) (*Filter, os.Error) {
	contents, err := ioutil.ReadFile(fn)
	//flt := &Filter{fn, string(contents)}
	return &Filter{fn, string(contents)}, err
}

//this returns the k,v pair or nil
func ProcLine(line string) (string, string) {
	fmt.Printf("line: %v\n", line)

	return "key...", "value..."
}