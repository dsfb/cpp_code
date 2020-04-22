# how to use this tool?
cat <file> | grep <pattern>
grep <what do you find> <where do you find> # search in some file
grep <what> < <a path to a file> # the same
grep <what> <file> > <file with result> # write result to a file

# regular expressions
b       # one space (the space between words)
^$      # beginning and the end of line
^	      # start of line
$	      # end of file
*       # 0 or more
+       # 1 or more
?       # 0 or one (optional)
.       # exactly one except new line
{x}     # exactly x symbols
{a,b}   # range: from a to b
\.      # simple dot symbol
\n      # new line
\t      # tab
\d      # digit
\s      # space
\w      # word character (like [a-zA-Z])
[]      # some ranges or expected symbols
[0-9]   # all digits like \d
[a-z]   # range: from a to z like \w
[abc]   # a,b or c
[^abc]   # not abc
()      # group
|       # logical 'or'
(|)     # group with "or"
.{1,3} 	wczytać od 1 do 3 wymboli
.*	-   powtórzenie symbola wiele razy
?	-     optional symbol
.*?	-   non-greedy select

(six|seven|eight).*\1 - coś się spotyka więcej niż jeden raz
(^\w|\w$)   # matches the first or last line symbol
[0-9]{2,}   # matches 2+ digits 
^[0-9]{3}$  # matches exactly 3 digits
[a-z0-9_]   # a-z, 0-9 and underscore
[0-9] 	- range of numbers
[^0-3] 	- not this numbers

# repeate patterns
.{1}    # exactly one times
.*      # 0 or more times   
.+      # 1 or more times
.?      # 0 or one

-- grep examples --
egrep -v ^$ file - remove all empty lines
grep -r -l "define" ./ - find all files that include "define" in current directory


# arguments
-i          # ignore case
-B <amount> # before
-A <amount> # after
-C <amount> # before and after
-n # it shows number of lines in a result
-n 	- wyświetlany jest numer linii w pliku w których znaleziono dany ciąg znaków;
--colour - highlight a result
-o 	- print  only  the  matched  (non-empty) parts (wydrukować jedynie wynik)
-i 	- ignore case
-E 	- extended regular expression (od teraz nie trzeba specjalne symbole poprzedzać za pomocą back slash)
-w	- szuka całego słowa
-C 1	- pokazać słowa, które są obok
-A 1 	- pokazać słowo obok, z dołu 
-B 1	- pokazać słowo obok, z góry
-v, 	- Invert the sense of matching, to select non-matching lines.
-r	- read all files  under  each  directory
-R	- read all files  under  each  directory + follow all links
-l 	- print names of files instead of matching values
-L 	- print names of files where match nothing
--include="*.conf" - pick files of certain type
-c 	- liczba wynoków


zipgrep - search files in a ZIP archive for lines matching a pattern
pdfgrep - seracg *.pdf fileszipgrep - search files in a ZIP archive for lines matching a pattern
pdfgrep - seracg *.pdf files

-- grep examples --
egrep -v ^$ file - remove all empty lines
grep -r -l "define" ./ - find all files that include "define" in current directory
