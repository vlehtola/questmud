inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(10);
  set_name("rat");
  set_animal(1);
  set_alias("rat");
  set_short("A dirty rat standing on its backfeet, trying to sniff air");
  set_long("The rats exists everywhere, in underground tunnels, in dark alleys, even\n"+
           "in the coldest place on earth. These little survivors is the curse of\n"+
           "mankind, spreading diseases and death all over the realm. It's a normally\n"+
           "looking rat with dirty fur, sharp teeth, long bony-tail, big brown\n"+
           "eyes and massive ears.\n");
  set_al(-1000);
  set_aggressive(0);

}
