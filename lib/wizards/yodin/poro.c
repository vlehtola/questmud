inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("deer");
set_alias("deer");
switch(a) {

case 0 : set_level(80+random(5));
set_short("small deer");
set_gender(1);
set_alt_name("deer");

break;
case 1 : set_level(80+random(3));
set_short("Old deer");
set_gender(1);
set_alt_name("deer");

break;
case 2 : set_level(75+random(20));
set_short("Huge deer");
set_gender(0);
set_alt_name("deer");
break;
}
 set_long("Mjoohon kattoppa pikku peuraa omg lol xiit nooob lol.\n");
}