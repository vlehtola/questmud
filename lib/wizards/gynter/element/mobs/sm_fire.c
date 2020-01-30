inherit "obj/monster";

reset(arg) {
  object armour,weapon;
  int i;
    ::reset(arg);
  if(arg) { return; }
set_race("demon");
  i = random(2);
  set_level(5+i*5);
  set_name("demon");
  set_alias("demon");
  set_short("A small fire demon");
  set_long("This is the scouts of the fire guards.\n" +
           "The only thing they got in their minds is\n" +
           "to make life hard for other creatures.\n");
  set_al(5);
  set_aggressive(0);

  weapon = clone_object("/wizards/gynter/element/eq/smf_blade");
  move_object(weapon, this_object());
  init_command("wield blade");
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
