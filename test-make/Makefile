d.txt: c.txt
	type c.txt > d.txt
	echo ddd>> d.txt

c.txt: a.txt b.txt
	type a.txt > c.txt
	type b.txt >> c.txt
	echo ccc >> c.txt

a.txt:
	echo aaa > a.txt
	
b.txt:
	echo bbb > b.txt

clean:
	del *.txt

