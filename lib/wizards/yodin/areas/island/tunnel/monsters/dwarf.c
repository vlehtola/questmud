inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_race("dwarf");
set_name("dwarf");
set_alias("miner");
switch(a) {

case 0 : set_level(22+random(3));
set_short("A dirty looking dwarf");
set_gender(1);
set_alt_name("dwarf");

break;
case 1 : set_level(25+random(3));
set_short("A dwarf mining some minerals");
set_gender(1);
set_alt_name("dwarf");

break;
case 2 : set_level(24+random(3));
set_short("A angry lookin dwarf");
set_gender(0);
set_alt_name("dwarf");
break;
}
 set_long("This is a small miner dwarf. Dwarf looks very dirty \n" +
 			"and angry.\n");
}