package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 20; i++ {
		fmt.Print(rand.Intn(2))
	}
	fmt.Println()
}