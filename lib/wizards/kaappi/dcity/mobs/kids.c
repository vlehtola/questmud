inherit "obj/monster";
reset(arg) {
int a;
a = random(2);
::reset(arg);
if (arg) return;
set_race("dwarf");
set_name("dwarf");
set_alias("child");
set_al(60);
set_aggressive(0);
switch(a) {

case 0 : set_level(10+random(7));
set_short("A dwarven child");
set_gender(2);
set_long("A little dwarven child playing here.\n"+
         "She is dirty and she has badly ragged\n"+
         "clothes but it seems like she enjoys\n"+
         "being here with her friends.\n");
break;

case 1 : set_level(10+random(7));
set_short("A dwarven child");
set_gender(1);
set_long("A little dwarven child playing here.\n"+
         "He is dirty and he has badly ragged\n"+
         "clothes but it seems like he enjoys\n"+
         "being here with his friends.\n");
break;
  }
}
