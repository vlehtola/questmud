inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(7 + random(2));
  set_name("wolf-cub");
  set_alias("beast");
  set_race("wolf");
  set_alt_name("cub");
  set_animal(1);
  set_short("Gray wolf-cub");
  set_long("Small gray wolf-cub looks cute and funny. It has sharp teeth but doesn't\n"+
           "yet know how to attack with them properly. Cub looks very playful.\n"); 
  set_al(1);
  set_al_aggr(200);
}
