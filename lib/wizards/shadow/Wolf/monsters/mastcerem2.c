inherit "obj/monster";
object weapon;
object armour,armour2;

reset(arg) {
   ::reset(arg);
if(arg) return;
set_name("master of ceremonies");
set_level(47);
set_race("human");
set_mage();
set_alias("master");
set_short("The Master of Ceremonies");
set_long("A grim, powerful looking man. He is assuredly one\n"+
         "of the religious leaders here.\n");
set_aggressive(0);
set_spell_chance(60, "exs brr blt");
set_skill("cast essence", 70);
set_skill("cast ice", 70);
set_skill("cast bolt", 70);
set_skill("mana control", 70);
set_skill("chanting", 70);

weapon = clone_object("/wizards/shadow/Wolf/weapons/cereaxe");
move_object(weapon, this_object());
init_command("wield axe");

armour = clone_object("/wizards/shadow/Wolf/armour/cerehood");
move_object(armour, this_object());
init_command("wear cloak");

armour2 = clone_object("/wizards/shadow/Wolf/armour/ring");
move_object(armour2, this_object());
init_command("smile");
}









