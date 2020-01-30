inherit "obj/monster";

reset(arg) {

int a,i;

::reset(arg);

if(arg) return;

i = random(2);
a = random(5);
set_race("human");
set_name("Dweller");
set_alias(({"dweller"}));
set_gender(1);
set_long("These twisted humans who lives in dark caves\n"+
"are called 'dark dwellers'. They can see in dark\n"+
"and they heard well. They wear only little skirts\n"+
"on their hips. They usually wield bludgeons but some\n"+
"of them can also cast spells.\n");
set_aggressive(i);
switch(a) {
case 0 : set_level(10+random(3));
set_short("Young, dark dweller");
break;
case 1 : set_level(15+random(3));
set_short("Dark dweller");
set_skill("kick", 60);
break;
case 2 : set_level(20+random(3));
set_short("Big, dark dweller");
set_skill("kick", 80);
break;
case 3 : set_level(25+random(3));
set_spell_chance(60, "exs brr blt");
set_skill("cast essence", 90);
set_skill("cast ice", 90);
set_skill("cast bolt", 90);
set_skill("mana control", 70);
set_short("Dark dweller mage");
break;
case 4 : set_level(25+random(3));
set_short("Dark dweller giant");
set_skill("kick", 100);
break;
}
}
