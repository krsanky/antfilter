package file

import "io/ioutil"

// making the var/fn name Capital exports it:
func Read() {
	contents,_ := ioutil.ReadFile("/etc/passwd")
	println(string(contents))
	//ioutil.WriteFile("filename", contents, 0x777)
	//return contents
}
