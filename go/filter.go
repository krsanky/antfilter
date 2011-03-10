package filter

import (
	//"os"
	//"io/ioutil"
	"strings"
	//"fmt"
)

//this returns k, v, b (key, val, bool)
//bool says if its successful
func ProcLine(line string) (string, string, bool) {
	line = strings.Trim(line, "\n\r\t ")

	if len(line) < 1 {
		//fmt.Printf("blank[%v]\n", line)
		return "", "", false
	} else if line[0] == '#' {
		//fmt.Printf("comment[%v]\n", line)
		return "", "", false
	}

	//split on the 1st '=':
	tmp := strings.Split(line, "=", 2)
	//fmt.Printf("tmp[%v]\n", tmp)

	//return "key...", "value..."
	if len(tmp) > 1 { //because Split returns a blank 1 elem. array ?
		return strings.Trim(tmp[0], " \n\t\r"), strings.Trim(tmp[1], " \n\t\r"), true
	}
	//fmt.Printf("blank\n")
	return "", "", false
}


