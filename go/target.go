package target

import (
	"fmt"
	"bytes"
	//"strings"
)

func ReplaceToken(tok string, val string, file *[]byte) *[]byte {
	tok = "@" + tok + "@"

	//fmt.Printf("tok[%v] val[%v]\n", tok, val)
	//fmt.Printf("file:\n%s\n", file)

	//arr := []byte
	arr := bytes.Replace(*file, []byte(tok), []byte(val), -1) // num replacements -1 for "all"

	//fmt.Printf("arr:\n%s\n", arr)
	//fmt.Printf("file:\n%s\n", file)

	return &arr
}

// file is the contents of the target file.
// fmap is the map of filter name to replacement val
func ReplaceTokens(file *[]byte, fmap *map[string] string) *[]byte {
	for k, v := range *fmap {
		//fmt.Printf("k:%v v:%v\n", k, v)

		arr := ReplaceToken(k, v, file)
		fmt.Printf("arr:\n%s\n", arr)
		file = arr
	}
	return file
}
