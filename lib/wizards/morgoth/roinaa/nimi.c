inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(1);
  set_name(""+this_player()->short()+"");
  set_alias(""+this_player()->short()+"");
  set_short(""+this_player()->short()+"");
  set_long(""+this_player()->short()+"\n");
  set_al(0);
}

