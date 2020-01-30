inherit "obj/monster";

reset(arg) {
  int i;
	  ::reset(arg);
  if(arg) { return; }
  i = random(2);
  set_level(30+i*5);
  set_name("stone giant");
  set_alias("giant");
  set_short("A large stone giant");
  set_long("This is one of the slaves of the granit giants. They are about 8ft high and made\n"+
           "out of solid stone. It is a miracle that it is able to move.\n");
  set_al(0);
  set_aggressive(0);

}

init() {
  int slump;
  ::init();
  slump = random(4);
  if(slump == 0) set_block_dir("north");
  if(slump == 1) set_block_dir("south");
  if(slump == 2) set_block_dir("east");
  if(slump == 3) set_block_dir("west");
}
