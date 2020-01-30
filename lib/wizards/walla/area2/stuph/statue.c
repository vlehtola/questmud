reset(arg) {
  /* This is an example of how you make an eq that when you do something */
  /* it will turn into a monster. The mobfile in this case is geenie.c */
  /* Just a normal mobfile */
  if(arg) return;
}

id(str) {
  return str == "statue";
}
short() {
  return "A huge statue of a blue dragon";
}
long() {
  write("The statue of the blue dragon has been erected here in order\n");
  write("for the monks, to pray to their gods. The statue is made out of\n");
  write("jade, and you start to feel somewhat small in the presence of.\n");
  write("this divine creature. As you look further, you notice that the\n");
  write("eyes of the dragon are actually flames, and they seem to be watching you.\n");
}
query_weight() {
  return  1;
}
get(str) {
    if (str == "statue") {
        write("Now, that wouldn't be appropriate, would it?\n");
    return 0;
 }
    return 0;
}

 
/* Adding an action for the lamp. So if someone 'rub' it 'rubbing(str) will be called */
init() {
  add_action("preier","pray");
}
 
preier(str) {
    /* if typed wrong nothing happends */
  if(!str) return 0;
  if(str == "statue") {
    write("You fall to your knees, and whisper a silent prayer to the dragon god.\n");
    write("Suddenly, the dragon comes alive, and starts beating it's wings furiously\n");
    write("making it change color!\n");
    /* calls the function nuke() */
    call_out("nuke", 1);
    return 1;
  }
}
 
nuke() {
  object monster;
  say(this_player()->query_name()+" falls down on his knees, and prays.\n");      
  /* Clones the monster as an object (as normally) */
  monster = clone_object("/wizards/walla/area2/mobs/reddragon");
  /* moves the monster into the room where the player that rubbed the lamp is */
  move_object(monster, environment(this_player()));
  /* destroys the lamp */
  destruct(this_object());
  return 1;
}
