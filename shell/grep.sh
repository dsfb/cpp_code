grep <what do you find> <where do you find> # search in some file
grep <what> < <a path to a file> # the same
grep <what> <file> > <file with result> # write result to a file


-- grep examples --
egrep -v ^$ file - remove all empty lines
grep -r -l "define" ./ - find all files that include "define" in current directory


# arguments 
-n # shows number of lines in a result
--colour - highlight a result
-n 	- wyświetlany jest numer linii w pliku w których znaleziono dany ciąg znaków;
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


-- regular expression --
^	- start of line
$	- end of file
. 	- any single character 
.{1,3} 	- wczytać od 1 do 3 wymboli
.*	- powtórzenie symbola wiele razy
?	- optional symbol
.*?	- non-greedy select
[0-9] 	- range of numbers
[^0-3] 	- not this numbers
b 	- granica słowa
|	- or operator
(six|seven|eight).*\1 - coś się spotyka więcej niż jeden raz



zipgrep - search files in a ZIP archive for lines matching a pattern
pdfgrep - seracg *.pdf files