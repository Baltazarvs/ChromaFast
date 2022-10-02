ChromaFast v1.0 by Nitrocell

This simple program converts RGB888 color format (#CCCCCC) to
SNES's BGR555 format ($CCCC). Usage is simple. Just open CMD or
terminal and type chromaf.exe or ./chromaf.

However, there is one special thing! If you don't want any prompts,
you can input requested RGB888 color as argument like:
	chromaf.exe CCCCCC
	./chromaf CCCCCC

There are rules for color:
	- Color <= FFFFFF aka. must have six digits.
	- Color > FFFFF aka. must have six digits again.
	- Allowed characters are only 0-9 A-F (ofc. it's hexadecimal...)

Future Plans:
	-I will add feature that will allow multiple colors conversion
	(e.g. ./chromaf FF0000 00FF00 FFFFFF ...) with options prompt
	if args not specified.
	
	-Conversion from BGR555 to RGB888.

Have questions? Let's talk. PM me on https://smwc.me/u/32854, or send me message on
Discord.

Cheers!