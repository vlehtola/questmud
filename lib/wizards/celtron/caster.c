inherit "/obj/monster";

reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mage");
  set_short("A mage");

  set_level(31);
  set_mage(1);
}
