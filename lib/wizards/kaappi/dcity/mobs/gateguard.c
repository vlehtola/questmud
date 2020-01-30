inherit "obj/monster";

reset(arg) {
object armour;
object weapon;
object weapon2;
  ::reset(arg);
  if(arg) { return; }
  set_level(70+ random(10));
  set_str(query_str() + 300);
  set_name("dwarf");
  set_race("dwarf");
  set_alias("guard");
  set_gender(1);
  set_skills("tumble", 100);
  set_skills("counter spell", 100);
  set_skills("double strike", 100);
  set_skills("strike", 100);
  set_skill_chance("strike",50);
  set_short("Dwarf gateguard");
  set_long("Very strong looking dwarf. He has a long beard which is\n"+
           "tied under his belt. He is armed to teeth and he seems\n"+
           "to be absolutely ready to use those weapons if it's needed.\n");
  set_al(40);
  set_al_aggr(200);
  set_aggressive(0);
  set_max_hp(query_hp() + 10000);
  set_hp(query_max_hp());

armour = clone_object("/wizards/kaappi/dcity/items/plate.c");
move_object(armour, this_object());
init_command("wear armour");

weapon = clone_object("/wizards/kaappi/dcity/items/shield.c");
move_object(weapon, this_object());
init_command("wield shield");

weapon2 = clone_object("/wizards/kaappi/dcity/items/axe.c");
move_object(weapon2, this_object());
init_command("wield axe");
}
