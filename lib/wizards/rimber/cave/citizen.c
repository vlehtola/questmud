inherit "obj/monster";

reset(arg) {
object weapon;
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_race("human");
set_name("dweller");
set_alias("dweller");
switch(a) {
case 0 : set_level(8+random(3));
set_short("Dark dweller child");
set_gender(1);
set_alt_name("child");
break;
case 1 : set_level(20+random(3));
set_short("Dark dweller citizen");
set_gender(1);
set_alt_name("citizen");
weapon = clone_object("/wizards/rimber/cave/obj/club.c");
move_object(weapon, this_object());
init_command("wield club");
break;
case 2 : set_level(17);
set_short("Dark dweller mage");
set_gender(2);
set_alt_name("mage");
set_spell_chance(80, "exs brr blt");
set_skill("cast essence", 100);
set_skill("cast ice", 100);
set_skill("cast bolt", 100);
set_skill("mana control", 80);
break;
}
 set_long("These twisted humans who live in dark caves\n"+
"are called 'dark dwellers'. They can see in dark\n"+
 "and they hear well. They wear only little skirts\n"+
 "round their waist, and they usually wield bludgeon weapons.\n"+
 "Some of them can even cast simple spells.");
}
