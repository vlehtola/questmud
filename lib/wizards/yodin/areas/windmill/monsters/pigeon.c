inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("pigeon");
set_alias("pigeon");
switch(a) {

case 0 : set_level(3+random(2));
set_short("Small cute pigeon");
set_gender(1);
set_alt_name("pigeon");

break;
case 1 : set_level(2+random(1));
set_short("Grey pigeon flying around");
set_gender(1);
set_alt_name("pigeon");

break;
case 2 : set_level(1+random(2));
set_short("Black pigeon sitting on the rock");
set_gender(0);
set_alt_name("pigeon");
break;
}
 set_long("A small pigeon. This pigeon looks quite ill.\n" +
          "It seems to missing few feathers.\n");


 }