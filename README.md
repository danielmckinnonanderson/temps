# Fahrenheit & Celsius converter

I'm going through the K&R "C bible" and #LearningInPublic.

Starting with the example Fahrenheit & Celsius conversion table program demonstrated in chapter 1 of the book,
I wanted to take this further and build it into a more full-fledged command line program that accepts its input through CLI arguments.


## Example usage

First, compile the program.
```
$ gcc f2c.c -o temps 
```

Convert a temp in Fahrenheit to a temp in Celsius
```
$ ./temps -f 72
22.222222
```

Convert a temp in Celsius to a temp in Fahrenheit
```
$ ./temps -c 15
59.000000
```

Print a short help message
```
$ ./temps -h
...
```
