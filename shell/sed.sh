sed - is stream editor

sed <pattern> <file>
sed "s/<what you want to replace>/<new text>/"
sed "s/pattern/replacement/flags"
s - means a substitute (zastąpić) operation

-- flags --
<some number> 	- opracowywać jedynie podaną liczbę wystąpień 
g 		- means that sed work with all matches
p 		- print the current pattern space.
w <file> 	- writes a result into a file

\/ 		- is forward-slash

-- exapmples --
sed "=" - prints number of lines
sed -n "/<template>/=" - prints numbers of lines than fits <template>
sed 's!/bin/bash!/bin/csh!' /etc/passwd - swój własny symbol rozdzielający !
sed -e "s///; s///" <file> - do couple operations
sed -f <file witch contains commands> <work file>

-- range of lines --
sed "2s///" - performes a task only on line number 2
sed "1,10s///" - set a range of lines for edit
sed "10,$s///" - sed will work from 10th line to end line
sed "/<text>/s///" - performs command when line starts at <text>

-- remove -- 
sed "3d" - removes 3th line
sed "1,10d" - removes lines from 1 to 10 including
sed "10,$d" - removes lines from 10 to end of file
sed "/<template>/d" - removes bu using <template>
sed "/<template1>/,/<template2>/d" - usuwa zakres gdzie spotykają się szablony

-- paste a text -- 
echo "Another test" | sed 'i\First test ' - wkleić przed tekstem
echo "Another test" | sed '8i\First test ' - wkleić przed ósmą linią
echo "Another test" | sed 'a\First test ' - skleić po tekscie
echo "Another test" | sed '8a\First test ' - skleić po ósmej linii
sed "10r <file1> file2 - połączyć pliki, dodając zawartość <file1> po 10 linii
sed '/<template>/r newfile' myfile - wstawić zawartość pliku po wystąpieniu <template>

-- replace --
sed '3c\<new text>' myfile - replace line number three
sed "/<old line starts at this text>/c <new text>" - zastąpić linie, które się zaczynają od
sed "y/123/456" - replace 1 -> 4, 2 -> 5 ...






















