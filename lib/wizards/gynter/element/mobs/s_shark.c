inherit "obj/monster";

reset(arg) {
	  int i;
  ::reset(arg);
  if(arg) { return; }
  i = random(2);
  set_level(9+i*5);
  set_name("small shark");
  set_alias("shark");
  set_short("A small shark");
  set_long("This is a small shark, about three years old. And dumb as hell.\n");
  set_al(-20);
  set_aggressive(0);
  set_animal(1);

}

init() {
  int slump;
  ::init();
  slump = random(6);
  if(slump == 0) set_block_dir("northeast");
  if(slump == 1) set_block_dir("southeast");
  if(slump == 2) set_block_dir("east");
  if(slump == 3) set_block_dir("west");
  if(slump == 4) set_block_dir("northwest");
  if(slump == 5) set_block_dir("southwest");
}
