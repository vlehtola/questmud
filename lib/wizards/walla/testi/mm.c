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
  write("see a lump of rags in one end of the cage. The\n");
  write("eyes of the dragon are actually flames, and they seem to be watching you.\n");
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
  write("As you rub the lamp it starts to shine with a very bright light,\n");
  write("and a surge passed through your body causing you to drop the lamp.\n");
  write("When the lamp touches the ground it transforms into a magical geenie!\n");
  /* calls the function nuke() */
  call_out("nuke", 1);
  return 1;
  }
}
 
nuke() {
  object monster;
  shout("A terrible roar can be heard as the dwarven warlock is released from his emprisonment.\n");
  /* Clones the monster as an object (as normally) */
  monster = clone_object("/wizards/gynter/element/eq/geenie");
  /* moves the monster into the room where the player that rubbed the lamp is */
  move_object(monster, environment(this_player()));
  /* destroys the lamp */
  destruct(this_object());
  return 1;
}





