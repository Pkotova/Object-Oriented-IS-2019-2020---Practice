#include <iostream>
#include"Compiled.h"
#include"Interpreted.h"
#include"VirtualMachine.h"
#include "User.h"
// is-a - isa relationship
// has-a 

// The elephant is a animal => bool isBodyBig()
// inheritance 
// The elephant has a big body => bool isBodyBig() => true 

// Animal - main class -> Elephant
// Elephant : public Animal
// Animall::print(){x}
// Elephant::print(){y}
int main()
{ 

	Compiled visualBasic("Visual Basic", 1991, "Microsoft", "Object - based and Event - driven",
		"Private Sub Form_Load() Execute a simple message box that says Hello, World!  MsgBox Hello, World!  End Sub",
		30, "Visual Studio", "16.0"),

		swift("Swift", 2014, "Chris Lattner", "Multi paradigm",
			"Hello, World! Program import Swift print Hello, World!)",
			50, "App Code", "5.2.2"),

		go("GO", 2009, "Robert Griesemer", "Multi Paradigm",
			"package main import fmt func main() {fmt.Println(hello world)}",
			30, "GoLand", "1.14.2");
	

	Interpreted php("PHP", 1995, "Rasmus Lerdorf", "Multi paradigm",
		"<?php echo '<p>Hello World</p>'; ?>", 20, "Web"),

		javaScript("Java Script", 1995, "Brendan Eich", "event - driven, functional, imperative",
			"script>	alert('Hello, world!');< / script>", 20, "WEB"),

		python("Python", 1990, "Guido van Rossum", "Multi - paradigm",
			"print(Hello, World!)", 40, "Shell");

	VirtualMachine java("Java", 1995, "James Gosling", "Multi paradigm",
		"public class HelloWorldApp { public static void main(String[] args) {System.out.println(Hello World!);}",
		10, "JVM"),

		scala("Scala", 2004, "Martin Odersky", "Multi Paradigm",
			"object HelloWorld extends App{ println(Hello, World!)}", 40, "Java virtual machine"),

		cs("C-sharp", 2000, "Microsoft", "Structured, imperative, object - oriented, event - driven task - driven, functional, generic, reflective, concurrent",
			"Console.WriteLine(Hello World!);", 10, "CLR");

	Vector<ProgrammingLanguage*> pl;
	pl.push(&php);
	pl.push(&java);
	pl.push(&go);


	std::cout << "------------------" << std::endl;
	User dimitar("Dimitar Tonchev", 21), petya("Petya Kotova", 20), daniel("Daniel Shahanski", 21);
	dimitar.setProgrammingLanguages(pl);

	std::cout << dimitar.calculateTime() << std::endl;
}

