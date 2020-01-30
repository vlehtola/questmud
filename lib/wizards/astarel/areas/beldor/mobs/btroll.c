#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.

inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;

    set_name("Troll");
    set_alias("troll");
    set_alt_name("guard");
    set_short("Huge troll guarding the bridge");
    set_long("Tulee joskus\n");
    set_level(20+random(10));
    set_race("troll");
    set_al(-60);
    set_block_dir("south");
    set_al_aggr(50); // -10 - 100 aggroes?
   
}