inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("moose");
set_alias("moose");
switch(a) {
case 0 : set_level(19+random(5));
set_short("A large moose eating here");
set_gender(0);
set_alt_name("moose");

break;
case 1 : set_level(17+random(5));
set_short("Huge brown moose");
set_gender(0);
set_alt_name("moose");

break;
case 2 : set_level(13+random(10));
set_short("A humongous moose staring at you");
set_gender(0);
set_alt_name("moose");
break;
}
 set_long("Moose are large even-toed herbivorous mammals,\n" +
          "the largest of the deer family. It has long,\n" +
          "lighter-colored legs with the front pair longer\n" +
          "than the hind ones. It has a long nose and \n" +
          "drooping lip.\n");


 }