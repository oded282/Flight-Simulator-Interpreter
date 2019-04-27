NOTE: 
- The interpreter gets "flightGear" valid arguments only
- Make sure you run our Interpreter before running FlightGear
- Sleep command is implemented by sleeping the amount inputed in milliseconds!

Implement Two arguments in the Settings -> Additional Settings box:
--generic=socket,out,10,XXX.XXX.XXX.XXX,5400,tcp,generic_small -
the i.p. of computer running interpreter
(Put the included generic small xml file in the FlightGear installation folder "data/Protocol").   
--telnet=socket,in,10,XXX.XXX.XXX.XXX,5402,tcp -
the i.p. of computer running FlightGear

The interpreter support command-line input and file input.

The interpreter will run until "exit" command sent.

Each argument sent via running the exexcutable file is read and executed command by command.

The interpreter lexes the input, than parses it. In case the command and paramaters is valid, it will be executed immediately.
Each command is represented by a Command object that implements the Command abstract class.
while the interpreter runs, another thread runs in the background updating the symbol table with current values read from FlightGear.
