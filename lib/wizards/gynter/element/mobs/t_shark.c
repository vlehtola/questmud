inherit "obj/monster";

reset(arg) {
	  int i;
  ::reset(arg);
  if(arg) { return; }
  i = random(2);
  set_level(5+i*5);
  set_name("tiny shark");
  set_alias("shark");
  set_short("A tiny shark");
  set_al(-15);
  set_long("This is a newly born shark. It has practicly no defences what so ever.\n");
  set_aggressive(0);
  set_animal(1);
  set_exp(query_exp()-(query_exp()/50));

}

init() {
  int slump;
  ::init();
  if (slump == 0) set_block_dir("north");
  if (slump == 1) set_block_dir("south");
  if (slump == 2) set_block_dir("east");
  if (slump == 3) set_block_dir("west");
}
