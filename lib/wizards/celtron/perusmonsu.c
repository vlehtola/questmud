inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(20);
  set_name("master");
  set_short("Arena master");
  set_block_dir("out");
}

