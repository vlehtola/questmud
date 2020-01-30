inherit "obj/monster";

reset(arg) {
object weapon;
    int i, a;
i = random(2);
a = random(5);
::reset(arg);
if(arg) return;
set_race("human");
set_name("Dweller");
set_alias("dweller");
set_gender(1);
set_aggressive(i);
weapon = clone_object("/wizards/rimber/cave/obj/club.c");
move_object(weapon, this_object());
init_command("wield club");
switch(a) {
case 0 : set_level(20+random(3));
 set_short("Young dark dweller");
break;
case 1 : set_level(25+random(3));
set_short("Dark dweller");
set_skill("kick", 60);
break;
case 2 : set_level(30+random(3));
 set_short("Big dark dweller");
set_skill("kick", 80);
break;
case 3 : set_level(32+random(3));
set_spell_chance(60, "exs brr blt");
set_skill("cast essence", 90);
set_skill("cast ice", 90);
set_skill("cast bolt", 90);
set_skill("mana control", 70);
set_alt_name("mage");
set_short("Dark dweller mage");
break;
case 4 : set_level(35+random(3));
set_short("Dark dweller giant");
set_alt_name("giant");
set_skill("kick", 100);
break;
}
 set_long("These twisted humans who live in the dark caves\n"+
"are called 'dark dwellers'. They can see in dark\n"+
 "and they hear well. They wear only little skirts\n"+
 "around their waist, and they usually wield bludgeon weapons.\n"+
 "Some of them can even cast simple spells.\n");
}
