inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("bunny");
set_alias("bunny");
switch(a) {

case 0 : set_level(3+random(2));
set_short("Small white bunny");
set_gender(1);
set_alt_name("bunny");

break;
case 1 : set_level(2+random(1));
set_short("Small brown forest bunny");
set_gender(1);
set_alt_name("bunny");

break;
case 2 : set_level(1+random(2));
set_short("Happy bunny jumping here");
set_gender(0);
set_alt_name("bunny");
break;
}
 set_long("Small and fluffy bunny jumping happily. Bunny has long .\n" +
          "and pointy ears. Bunny watches carefully your movements.\n");


 }