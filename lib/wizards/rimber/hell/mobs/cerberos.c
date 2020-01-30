inherit "obj/monster";

reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_level(50);
 set_race(animal);
 set_name("cerberos");
 set_alias("cerberos");
 set_al(-30);
 set_short("A three headed beast called Cerberos");
 set_long("Cerberos on koira.\n");
 if(this_player()->query_alignment() >= 0) {
  set_block_dir("north");
 }
}
