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

case 0 : set_level(18+random(5));
set_short("Small deer eating grass.");
set_gender(1);
set_alt_name("deer");

break;
case 1 : set_level(13+random(10));
set_short("Old deer eating grass.");
set_gender(1);
set_alt_name("deer");

break;
case 2 : set_level(11+random(20));
set_short("Huge deer eating grass.");
set_gender(0);
set_alt_name("deer");
break;
}
 set_long("Deer is here eating some grass. It has small and spiky \n" +
 					"antlers. Deer is very old and looks like it's very ill and \n" +
 					"undernourished. Deer looks at you very sadly.\n");
}