inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_race("human");
set_name("child");
set_alias("human");
switch(a) {
case 0 : set_level(5+random(5));
set_short("Small boy playing with ball");
set_gender(1);
set_alt_name("boy");

break;
case 1 : set_level(2+random(5));
set_short("A dirty looking boy");
set_gender(1);
set_alt_name("boy");

break;
case 2 : set_level(5+random(3));
set_short("Little boy running around you");
set_gender(1);
set_alt_name("boy");
break;
}
 set_long("Small boy looks pretty dirty and dusty. He has some\n" +
          "old clothes on and too big hat. Boy looks very happy.\n");


 }