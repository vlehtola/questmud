inherit "/obj/monster";

reset(arg) {
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(3);
  set_mage(1);
  set_level(30+i*4);
  set_name("elf");
  set_short("A beautiful Elf");
  set_long("A tall beautiful elf is standing here watching over the forest.\n"+
           "He has long brown hair and a headband to hold it back. His eyes\n"+
           "constantly searches the surrounding area for signs of agression.\n");
  set_gender(1);
}