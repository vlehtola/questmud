reset(arg) {
  /* This is an example of how you make an eq that when you do something */
  /* it will turn into a monster. The mobfile in this case is geenie.c */
  /* Just a normal mobfile */
  if(arg) return;
}
 
id(str) {
  return str == "cage";
}
short() {
  return "A huge cage";
}
long() {
  write("You see before you, a huge cage, made of solid iron. The bars\n");
  write("are almost as thick as your arm, and the cage seems to be glowing\n");
  write("with a faint blue glow, indicating some spell cast on it. You can\n");
  write("see a lump of rags in one end of the cage.\n");
}
query_weight() {
  return  1;
}
get() {
  return 0;
}
 
/* Adding an action for the lamp. So if someone 'rub' it 'rubbing(str) will be called */
init() {
  add_action("avaa","open");
}
 
avaa(str) {
    /* if typed wrong nothing happends */
  if(!str) return 0;
  if(str == "cage") {
  write("As you fumble with the gate of the cage, you see the rags on the floor\n");
  write("start to move, and two spots of fiery light awaken. You start to feel that\n");
  write("maybe opening the cage was NOT such a good idea.\n");
  /* calls the function nuke() */
  call_out("nuke", 1);
  return 1;
  }
}
 
nuke() {
  object monster;
  shout("A terrible roar can be heard as the dwarven death knight is released from his emprisonment.\n");
  /* Clones the monster as an object (as normally) */
  monster = clone_object("/wizards/gynter/element/eq/geenie");
  /* moves the monster into the room where the player that rubbed the lamp is */
  move_object(monster, environment(this_player()));
  /* destroys the lamp */
  destruct(this_object());
  return 1;
}







