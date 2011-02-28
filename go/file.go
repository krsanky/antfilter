/*
> All-

> I've just started poking around with Go.  So far, I like it.  However
> I have run into an issue with opening a text file specified by the
> user.

> fmt.Print("Please enter the name of the file you wish to open.\n");
> bufin := bufio.NewReader(os.Stdin);
> s, _ := bufin.ReadString('\n');
> result, err := io.ReadFile(s);

> When I hardcode s to be, say, "/test.txt", it works just fine.  But
> when I enter /test.txt, or any variation thereof into the input, Go
> doesn't seem able to find such a file.

> Any hints?

bufio.ReadString "return[s] a string containing the data up to and
including the delimiter."   Drop the newline.

result, err := io.ReadFile(s[0:len(s)-1]

assuming len(s) > 0.

-rob
*/

//------------------------------

/*
package main

import (
  "io/ioutil";
  )


func main() {
  contents,_ := ioutil.ReadFile("plikTekstowy.txt")
  println(string(contents))
  ioutil.WriteFile("filename", contents, 0x777)
}
*/
