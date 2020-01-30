reset(arg) {
  /* This is an example of how you make an eq that when you do something */
  /* it will turn into a monster. The mobfile in this case is geenie.c */
  /* Just a normal mobfile */
  if(arg) return;
}

id(str) {
  return str == "lamp";
}
short() {
  return "A magical lamp";
}
long() {
  write("This is Aladins magical lamp.\nMaybe you should try to 'rub' it?\n");
}
query_weight() {
  return  1;
}
get() {
  return 1;
}
 
/* Adding an action for the lamp. So if someone 'rub' it 'rubbing(str) will be called */
init() {
  add_action("rubbing","rub");
}
 
rubbing(str) {
    /* if typed wrong nothing happends */
  if(!str) return 0;
  if(str == "lamp") {
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
  say("The geenie stretches its arms to the sky. Greeting it once again.\n");
  /* Clones the monster as an object (as normally) */
  monster = clone_object("/wizards/gynter/element/eq/geenie");
  /* moves the monster into the room where the player that rubbed the lamp is */
  move_object(monster, environment(this_player()));
  /* destroys the lamp */
  destruct(this_object());
  return 1;
}
