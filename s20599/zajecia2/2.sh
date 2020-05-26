X=tekst
echo $X
bash
echo $X

Po uruchomieniu nowej powloki bash wartosc zmiennej X nie bedzie juz dostepna

X=Tekst dłuższy
echo $X

Zle przypisanie - nalezy uzyc "wartosc" lub 'wartosc' 

X="Tekst 1"
Y="tekst:$X"
echo "$Y"
Y='tekst:$X'
echo "$Y"
Y=tekst:$X
echo "$Y"

W "" znaki specjalne sa interpretowane a zmienne zamieniane na wartosci
W '' ciag znakow jest przepisywany 1:1 - nie mozna uzyc apostrofow w srodku