#include <iostream>
#include"Compiled.h"
#include"VirtualMachine.h"
#include"Interpreted.h"
#include"User.h"

int main()
{
//Compiled programming languages
	Compiled visualBasic("Visual Basic", 1991, "Microsoft", "Object - based and Event - driven",
		"Private Sub Form_Load() Execute a simple message box that says Hello, World!  MsgBox Hello, World!  End Sub",
		30, "Visual Studio", "16.0"),

		swift("Swift", 2014, "Chris Lattner", "Multi paradigm",
			"Hello, World! Program import Swift print Hello, World!)",
			50, "App Code", "5.2.2"),

		go("GO", 2009, "Robert Griesemer", "Multi Paradigm",
			"package main import fmt func main() {fmt.Println(hello world)}",
			30, "GoLand", "1.14.2");

//Programming anguages with virtual machine
	VirtualMachine java("Java", 1995, "James Gosling", "Multi paradigm",
		"public class HelloWorldApp { public static void main(String[] args) {System.out.println(Hello World!);}",
		10, "JVM"),

		scala("Scala", 2004, "Martin Odersky", "Multi Paradigm",
			"object HelloWorld extends App{ println(Hello, World!)}", 40, "Java virtual machine"),

		cs("C-sharp", 2000,"Microsoft" ,"Structured, imperative, object - oriented, event - driven task - driven, functional, generic, reflective, concurrent",
			"Console.WriteLine(Hello World!);", 10, "CLR");

//Interpreted programming languages
	Interpreted php("PHP", 1995, "Rasmus Lerdorf", "Multi paradigm",
		"<?php echo '<p>Hello World</p>'; ?>", 20, "Web"),
		
		javaScript("Java Script", 1995, "Brendan Eich", "event - driven, functional, imperative", 
			"script>	alert('Hello, world!');< / script>", 20, "WEB"),
		
		python("Python", 1990, "Guido van Rossum", "Multi - paradigm",
			"print(Hello, World!)", 40, "Shell");

	
	User dimitar("Dimitar Tonchev",21), petya("Petya Kotova",20), daniel("Daniel Shahanski",21);
	dimitar.addLanguage(cs);
	dimitar.addLanguage(php);
	dimitar.addLanguage(scala);
	std::cout << "Time needed for Dimitar: " << dimitar.calculateTime() <<" days"<< std::endl;
	
	petya.addLanguage(java);
	petya.addLanguage(python);
	petya.addLanguage(cs);
	//petya.removeLanguage("python");
	std::cout << "Time needed for Petya: " << petya.calculateTime() <<" days"<< std::endl;

	daniel.addLanguage(javaScript);
	daniel.addLanguage(go);
	daniel.addLanguage(swift);
	std::cout << "Time needed for Daniel: " << daniel.calculateTime() <<" days"<< std::endl;

	daniel.save();
	dimitar.save();
	petya.save();

	daniel.read();
}
