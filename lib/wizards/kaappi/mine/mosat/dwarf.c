inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(5) + 20);
  set_name("dwarf");
  set_race("dwarf");
  set_alias("miner");
  set_gender(1);
  set_short("Dwarven miner");
  set_long("A small but muscular dwarven miner.\n"+
      "He is wearing only dirty clothes and he has a mining pick\n"+
       "in his hand. Seems that he is very busy right now.\n");
  set_al(6);
  set_aggressive(0);
}
