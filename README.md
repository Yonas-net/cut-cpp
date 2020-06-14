# UNIQ-CPP

## ABOUT
UNIQ-CPP is a program developed by us right from the start and is an imitation of the standard uniq command. This 
program is only for learning and testing purposes and is therefore not suitable for larger projects.

Learn more about what the parameters mean and what they are for, see the bunch of uniq options below.
### Parameters

| short Options | long Options      |                 Usage |
| ----------- | ----------- |  ---------------- |
| -d  | --repeated   |  Display only a duplicated line|
| -c  | --count   |     Count how many times a line was repeated|
| -u  | --unique   |    Only output the first of several matches.       |
| -h  | --help  | Display this help and exit the Program.       |


### Usage
Firstly compile the code and this is done by doing the command as follows ``g++ -o uniq main.cpp``. 
And the compiled code is saved in the ``uniq`` file as ``binary code``.

Now we can e.g. execute the following commands to modify duplicated lines from the content of the ``in.txt`` file `.

content of ``in.txt`` file:
```
I love to code
I love to code
I love open source
I love open source
I love to code
I love open source
```

Now, execute this command and the output looks like this...
``./uniq in.txt`` OR ``./uniq < in.txt``.
```
I love to code
I love open source
I love to code
I love open source
```


The command above only checks two consecutive repeated lines, but not the whole file.

If you only want to print the repeated lines once in the whole file then you have to execute the following command
``./uniq -u int.txt`` OR ``./uniq -u < int.txt``
then the output looks like as expected.
```
I love to code
I love open source
```


If you want to know how many times a line has been repeated, execute this command ``./uniq -c in.txt``.

### CONTRIBUTING 
I hope you have as much fun with it as I have when coding and would be very happy if you would develop the program 
further or if you could give me suggestions how I can do it even better. 

Your are always welcome to contribute in this repository

Thank you :+1:
