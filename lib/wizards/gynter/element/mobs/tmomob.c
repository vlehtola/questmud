inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(500);
  set_name("granite giant");
  set_alias("giant");
  set_short("A granite giant");
  set_long("These are the true masters of the land of stone.\n" +
           "Noone, not even the stone lord himself dares to defie them.\n");
  set_al(0);
  set_aggressive(0);

  set_hp(1);
  set_str(0);
  set_dex(0);
  set_sp(0);
  set_ep(0);
  set_int(0);
  set_wis(0);
  set_con(1);
  
}
