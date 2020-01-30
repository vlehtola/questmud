inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(10);
  set_hp(300);
  set_race("giant");
  set_gender(1);
  set_name("guard");
  set_alias("giant");
  set_short("A weak giant soldier");
  set_long("This giant looks pretty weak for a giant. His movement reveals\n"+
	   "that he is no expert in battle.\n");
  set_block_dir("north");
}

