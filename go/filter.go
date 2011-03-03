package filter

import (
	"os"
	"io/ioutil"
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

