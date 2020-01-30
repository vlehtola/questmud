inherit "obj/monster";

reset(arg) {
object armour;
object weapon;
object weapon2;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(5) + 50);
   set_str(random(10)+350);
  set_name("dwarf");
  set_race("dwarf");
  set_alias("guard");
  set_gender(1);
  set_skills("tumble", 100);
  set_skills("counter spell", 100);
  set_skills("double strike", 100);
  set_skills("strike", 100);
  set_skill_chance("strike",25);
  set_short("Dwarf guard");
  set_long("Strong lookin dwarf guard standing here, to keep\n"+
          "unwanted things outside of this mine.\n");
  set_al(40);
  set_aggressive(0);
  set_max_hp(query_hp() + 10000);
  set_hp(query_max_hp());

armour = clone_object("/wizards/kaappi/mine/kamat/plate.c");
move_object(armour, this_object());
init_command("wear armour");
weapon = clone_object("/wizards/kaappi/mine/kamat/gshield.c");
move_object(weapon, this_object());
init_command("wield shield");

weapon2 = clone_object("/wizards/kaappi/mine/kamat/gaxe.c");
move_object(weapon2, this_object());
init_command("wield axe");
}
init() {
 ::init();
 add_action("mine","mine");
}
mine() {
 if(this_player()->query_level() > 100) {
 write("Guard blocks your way.\n");
return 1;
}
}
