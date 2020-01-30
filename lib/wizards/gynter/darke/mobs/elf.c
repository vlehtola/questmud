inherit "/obj/monster";

reset(arg) {
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(4);
  set_level(50+i*2);
  set_name("Dark elf");
  set_alias("elf");
  set_short("An old dark elf");
  set_long("A silver haired, old dark elf stand here in\n"+
           "the shadows feeling content with himself.\n"+
           "He has just finished the hardest task of his life.");
  set_gender(1);
  set_race("dark elf");
}
