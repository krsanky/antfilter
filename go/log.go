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


// func main() {
//     flName := "./test.txt"
// flPerm := 0666
// fl, flErr := os.Open(flName, os.O_CREAT|os.O_RDWR, flPerm)
// defer fl.Close()
// if flErr != nil {
//     fmt.Println("open:", flErr)
//                 return
// }
//
//         var line string
//
// rd := bufio.NewReader(fl)
//         var rdErr os.Error
// for rdErr == nil {
//     line, rdErr = rd.ReadString('\n')
//     if len(line) > 0 {
//         if rdErr != nil {
//             line += "\n"
//         }
//         fmt.Print(line)
//     }
// }
// if rdErr != os.EOF {
//     fmt.Println("read:", rdErr)
//                 return
// }
//
// _, flErr = fl.Seek(0, 2)
// if flErr != nil {
//     fmt.Println("seek:", flErr)
//                 return
// }
//
// wr := bufio.NewWriter(fl)
//         var wrErr os.Error
// line = "+append\n"
// _, wrErr = wr.WriteString(line)
// if wrErr != nil {
//     fmt.Println("write:", wrErr)
//                 return
// }
// wrErr = wr.Flush()
// if wrErr != nil {
//     fmt.Println("flush:", wrErr)
//                 return
// }
//
// }


/*
WriteFile always overwrites.
To append you have to open the file yourself.
Copy the source to WriteFile and open it with
os.O_APPEND instead of os.O_TRUNC.

godoc -src io/ioutil WriteFile
*/

