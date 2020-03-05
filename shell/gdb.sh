a dump core file - zrzut pamięci - gerenuje system operacyjny, gdy program pada	
apt-get install linux-crashdump - do generowania core plików
valgrind?
 trace ?
ltrace(1)?

/var/lib/systemd/coredump/
/var/crash - tu się znajdują core dump pliki, który tworzy apport
apport - program w Ubuntu, który zażądza core dump plikami, BUT it will only do so for applications installed from the main ubuntu apt repositories
systemctl status apport.service - sprawdzamy status apport
sudo systemctl enable apport.service 
sudo service apport start
ulimit -c unlimited


example debugging:
g++ -g program.cpp
g++ -ggdb program.cpp
gdb -s SYMBOLS_FILE -e PROGRAM_NAME
gdb -quiet PROGRAM_NAME
gdb PROGRAM_NAME --args arg1 arg2
gdb app.exe
(gdb) set args ch248ds 0
(gdb) show args
> break main
> layout next
> start
> backtrace full / bt
> next
> q / quit

gdb arguments:
man gdb - small documentation
info gdb - full documentation
-quiet - do not print the introductory and copyright messages.
-tty=device - Run using device for your program's standard input and output.
gdb ls -tty=/dev/pts/2 - przekierować output do innej konsoli
gdb -c <corefile> - You are also able to retrace a core file if you have one produced 
gdb -s <symfile> Read symbol table from file

gdb logging to a file:
(gdb) set logging file gdb-<program>.txt
(gdb) set logging on

gdb commands:
CTRL+C - If the program hangs but doesn't crash you can press ctrl+c in gdb and then continue with the `next` step. 
attach PROCESS_ID - attach to the process
sharedlibrary - jakie libraty program używa?
r / run  - run debugging
run ARG1 ARG2 - run with programs' arguments

symbol-file FILE_NAME - Read symbol table information from file filename. This loads symbols from the binary and from any shared libraries the binary uses. 
symbol-file PATH_TO_APP - trzeba załadować te symbole z programu, jeśli debugowanie odbywa się na podstawie core dump
bt / backtrace  - display the program stack
info stack -  display the program stack
where - display the program stack
backtrace full - pokazać miejsce gdzie program się rozjebał
up / down - przemieszczać się stosem
frame N - skakać na stosie w górę i w dół

info threads - a command to inquire about existing threads 
thread N - przełączyć się na wątek?
thread apply all bt full - Here’s how to get the stack for every thread in gdb!

b / break - make breakpoint
break [file:]function
break FUNCTION_NAME
break LINE_NUMBER
break main - set break in main function
break CLASS_NAME::FUNCTION_NAME - breakpoint in erase() function of list class
tbreak - jednorazowy break
clear - usunąć breakpoint na następnej linii kodu
clear FUNCTION_NAME  - delere all breakpoints in function
enable - włączyć wszystkie breakpoints
disable - odłączyć wszystkie breakpoints

(gdb) set args <argument one> <argument two>
(gdb) show args
info b - list of breakpoints
edit [file:]function - look at the program line where it is presently stopped
delete BREAK_POINT_NUMBER - delete break point
set args APP_ARG1 APP_ARG2 - podać argument do aplikacji
step - into function
watch VARIABLE_NAME - śledzić jakąś zmienną 
print VARIABLE_NAME_OR_EXPRESSION - prints out value of variable or expression
print *arr@10 - show array for 10 elements
print ARRAY[2] - print array's element
l / list - print 10 linet of code where am I
l LINE_NUMBER - List lines of source code centered around a particular line
n / next - Execute a single statement. If the statement is a function call, execute the entire function and return
s / step  - Execute a single statement. If the statement is a function call, just single step into the function
c - Continue running your program (after stopping, e.g. at a breakpoint).
finish - Execute the rest of the current function; that is, step out of the function. 
until - wykonać funkcję i powstrzymać program
set listsize NUMBER  - set the number of source lines to list
q / quit - exit



attach to the process:
1) gdb -p 12271
2) gdb /path/to/exe `pidof ...`

3) gdb /path/to/exe
(gdb) attach 12271

















