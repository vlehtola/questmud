inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(30);
  set_hp(query_hp()*3);
  set_race("giant");
  set_gender(1);
  set_name("guard");
  set_alias("giant");
  set_short("A strong giant soldier");
  set_long("This giant seems to be a good soldier. He's strong and dumb.\n");
  set_block_dir("west");
}

