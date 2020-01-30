inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/armman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/armb3");
  add_exit("west","wizards/nalle/jerusalem/arma2");
  add_exit("enter","wizards/nalle/jerusalem/bookstore");
  short_desc = "The Hart El-Yahud. Southern part.";
  long_desc =
"This is southern part of the Hart El-Yahud. Your surroundings\n" +
"seem quite prosperous enough, and even the sanitation is\n" +
"mediocre. Most of the shops seem to be closed right now\n" +           
"but one bookstore still looks like its open. There are a\n" +
"few people walking around here, and they seem like fairly\n" +
"honest, hard working individuals.\n";
}
 
init() {
    ::init();
   add_action("map", "map");
}
 
map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/amap");
   return 1;
}   


