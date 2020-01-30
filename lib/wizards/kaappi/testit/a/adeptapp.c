inherit "obj/monster";

reset(arg) {

int a;
  a = random(2);

::reset(arg);
  if(arg) return;

set_race("human");
set_alias("mage");

switch(a) {

case 0 :
    set_level(38);
    set_name("apprentice");
    set_gender(1);
    set_mage(0);
    set_al(-10);
    set_aggressive(0);

    set_short("A human apprentice archmage moaning here.");
    set_long("An apprentice archmage is moaning something about his\n"+
             "powers. He seems extremely sad and angry at the same time.\n");

    set_skill("cast essence", 100);
    set_skill("cast ice", 100);
    set_skill("cast fire", 100);
    set_skill("cast electric", 100);
    set_skill("mana control", 100);

  break;

case 1 :
    set_level(42);
    set_name("adept");
    set_gender(1);
    set_mage(1);
    set_al(-10);
    set_aggressive(0);

    set_short("Skilled human adept discussing on some matter.");
    set_long("This adept mage is discussing with another adept.\n"+
             "Both of them seem very worried and scared.\n");

    set_skill("cast essence", 100);
    set_skill("cast bolt", 100);
    set_skill("cast ice", 100);
    set_skill("cast fire", 100);
    set_skill("cast electric", 100);
    set_skill("mana control", 100);

  break;
 
 }
}
