inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 10);
  set_name("dwarf");
  set_race("dwarf");
  set_alias("child");
  set_gender(1);
  set_short("A dwarven child");
  set_long("A little dwarven child sitting on the ground\n"+
       "and playing strange game with some little rocks.\n");
  set_al(6);
  set_aggressive(0);
  set_special(100);
}
special_move() {
  object ob;
  ob = present("dalana", environment(this_object()));
  if(attacker_ob && ob) {
  tell_room(environment(this_object()), "Dalana says: 'Leave these children alone.'\n");
  ob->attack_object(attacker_ob);
return 1; }
}
