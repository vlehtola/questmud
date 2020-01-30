inherit "obj/monster";
  /* this is the mobfile for when you turn an eq into a mob */
  /* the magic all happens in /doc/examples/lamp.c so check that one out instead */

reset(arg) {
  object money, item;
  ::reset(arg);
  if(arg) { return; }
  set_level(10);
  set_mage(1);
  set_name("geenie");
  set_short("A geenie");
  set_long("A magical geenie. It was living in a lamp until someone set it free.\n");
  set_al(0);
  set_aggressive(0);
}
