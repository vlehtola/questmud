inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(1);
  set_name(""+this_player()->name()+"");
  set_alias(""+this_player()->name()+"");
  set_short(""+this_player()->name()+"");
  set_long(""+this_player()->name()+"\n");
  set_al(0);
}

