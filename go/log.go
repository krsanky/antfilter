package log

import (
	"log"
)

//var log_filename := "/tmp/antf.log"


func Debug(str string) {
	log.Printf("debug: %v\n", str)
}



//A simple example:
//
//func doWrite() (err os.Error) {
//    f, err := os.Open("somefile", os.O_RDWR | os.O_CREATE, 0666)
//    if err != nil {
//        return
//    }
//
//    defer f.Close()
//
//    _, err = f.Write([]byte("An array of bytes"))
//    if err != nil {
//        return // f.Close() will automatically be called now
//    }
//
//    // some other logic here
//
//    return // f.Close() will automatically be called now
//
//}