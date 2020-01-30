inherit "obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) { return; }

set_level(150);
set_max_hp(query_max_hp() * 2);
set_hp(query_max_hp());
set_name("jay");
set_alias("bob");
set_short("Jay and Silent Bob");
set_long("Jay and Silent Bob.\n");
   
}
