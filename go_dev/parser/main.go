package main

import (
		"fmt"
		"github.com/gocolly/colly"
		"log"
	)



func main() {

	fmt.Println("Hui")
	
	c := colly.NewCollector()

	c.OnHTML("h1", func(e *colly.HTMLElement) {
        log.Println("Title:", e.Text)
    })

    err := c.Visit("https://github.com/camel-ai/owl")
    if err != nil {
        log.Fatal(err)
    } 
}

