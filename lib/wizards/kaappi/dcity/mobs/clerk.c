inherit "obj/monster";
reset(arg) {
int a;
a = random(2);
::reset(arg);
if (arg) return;

set_race("dwarf");
set_name("dwarf");
set_alias("clerk");
set_al(60);
set_aggressive(0);
set_money(50);

switch(a) {

case 0 : set_level(30+random(10));
set_short("The dwarven clerk");
set_gender(1); 
set_long("A rigorous looking dwarven clerk. He has a long\n"+
         "brown beard. He has a large pile of papers in his\n"+
         "hands. There are couple of citizens discussing with him.\n");
break;

case 1 : set_level(30+random(10));
set_short("The dwarven clerk");
set_gender(2);
set_long("A rigorous looking dwarven clerk. She has a large\n"+
         "pile of papers in her hands. There are couple of \n"+
         "citizens discussing with her.\n");
break;
  }
}
