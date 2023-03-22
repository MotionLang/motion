## Dynamics (WIP)
```
## Creating the @message message
msg @message;

func messageFunc() {
	## A function that prints hello world when called.
	print "Hello World";
}

dynamic myDynamic|%| {
	## Init: sets the Dynamic's state upon initialization
	init: 
		return @ok;
	
	## Fault: Optional. Sends the specified message upon an error occuring in the dynamic.
	fault: 
		return @error;
	
	## Default: Runs if no other conditions are satisfied.
	default: 
		return @ok;
	
	## The % operator is a special paremeter. It referances the message given to the dynamic when called
	if(% == @message) {
		messageFunc();
		return @ok;
	}
	
}

## Initialize the dynamic
init myDynamic||;

## Send the message
myDynamic|@message|

```

Output:

```
