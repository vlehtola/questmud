inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_name("apprentice");
    set_alias("mage");
    set_race("human");
    set_gender(1);
     set_mage(0);
     set_al(-10);
     set_aggressive(0);
    set_al(-10);  
    set_aggressive(0);    
     set_level(38);
    set_short("A human apprentice archmage moaning here.");
    set_long("An apprentice archmage is moaning something about his\n"+
      "powers. He seems extremely sad and angry at the same time.\n");

set_skill("cast essence", 100);
set_skill("cast ice", 100);
set_skill("cast fire", 100);
set_skill("cast electric", 100);
set_skill("mana control", 100);
}
