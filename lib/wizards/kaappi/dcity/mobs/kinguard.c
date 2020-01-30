inherit "obj/monster";

reset (arg) {
object weapon,weapon2;

 ::reset(arg);
 if(arg) { return; }
 set_level(60+random(10));
 set_str(query_str() + 200);
 set_name("dwarf");
 set_race("dwarf");
 set_alias("guard");
 set_gender(1);
 set_skills("tumble", 100);
 set_skills("counter spell", 50);
 set_skills("reflect spell", 50);
 set_skills("attack", 100);
 set_skills("axes", 100);
 set_skills("cut", 100);
 set_short("King's Bodyguard");
 set_long("A sturdy and strong lookin guard.\n"+
          "He is absolutely ready to defend his mighty King\n"+
          "the evil bastards like you!\n");
set_aggressive(1);
set_dead_ob(this_object());

weapon = clone_object("/wizards/kaappi/dcity/items/shield.c");
move_object(weapon, this_object());
init_command("wield shield");

weapon2 = clone_object("/wizards/kaappi/dcity/items/axe.c");
move_object(weapon2, this_object());
init_command("wield axe");
}

monster_died() {
  if(present("king", environment(this_object()))) {
    present("king", environment(this_object()))->reduceapurit();
  }
 return 0;
}
