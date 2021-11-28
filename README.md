# testing
Software testing repo

## How the bash script works

Before launching it, make sure you export the PATH variable, adding the path of 
/usr/local/mut/bin to it IN FRONT OF the current PATH.
The script takes a single argument -- the name of the .txt file containing test sequences. 
It then runs the test sequences and tells about the results. After that, each mutant of the 
program being tested is launched against the current test sequence. The results are printer to standard output.

Warning: it does NOT generate mutants itself, so you've to do it prior to launching it with mut-gen.