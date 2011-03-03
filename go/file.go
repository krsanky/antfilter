package file

import (
	"os"
	"io/ioutil"
)

// // making the var/fn name Capital exports it:
// func Read() {
// 	contents, _ := ioutil.ReadFile("/etc/passwd")
// 	println(string(contents))
// 	//ioutil.WriteFile("filename", contents, 0x777)
// 	//return contents
// }


func Read(fn string) ([]byte, os.Error) {
	contents, err := ioutil.ReadFile(fn)
	//println(string(contents))
	return contents, err
}
