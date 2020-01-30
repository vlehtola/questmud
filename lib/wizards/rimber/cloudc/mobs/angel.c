inherit "obj/monster";

reset(arg) {
 object weapon;
 ::reset();
 if(arg) return;
 set_level(24);
 set_name("angel");
 set_alias("angel");
 set_short("An angel soldier");
 set_long("Angel summoned by Michael.\n");
 set_race("angel");
 set_al(30);
 set_gender(1);
 weapon = clone_object("/wizards/rimber/cloudc/obj/swordi.c");
 move_object(weapon, this_object());
 init_command("wield claymore");
 set_skill("cast essence", 80);
 set_skill("cast teleport", 80);
 set_skill("cast ice", 100);
 set_skill("mana control", 60);
 set_skill("mana control", 80);
 set_aggressive(1);
}

catch_tell(str) {
 string who, where;
 if(sscanf(str, "%s leaves %s", who, where) == 2) {
  init_command("cast exs brr trn at "+who);
 }
}
