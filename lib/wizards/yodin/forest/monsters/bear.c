inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("bear");
set_alias("bear");
switch(a) {

case 0 : set_level(28+random(3));
set_short("A gigantic bear eating berries.");
set_gender(1);
set_alt_name("bear");

break;
case 1 : set_level(28+random(3));
set_short("A Large bear climbing on the tree.");
set_gender(1);
set_alt_name("bear");

break;
case 2 : set_level(28+random(3));
set_short("A huge bear crowling here.");
set_gender(0);
set_alt_name("bear");
break;
}
 set_long("An enormous sized bear with fluffy fur. Bear is \n" +
 					 "almost completely black. It has very sharp \n" +
 					 "claws and very sharp teeth. This magnificent \n" +
 					 "piece of nature is very frightening and you \n" +
 					 "really should leave it alone.\n");
}