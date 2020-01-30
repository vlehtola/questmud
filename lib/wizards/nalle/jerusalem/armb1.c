inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/armwoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/armc1");
  add_exit("east","wizards/nalle/jerusalem/armb2");
  add_exit("south","wizards/nalle/jerusalem/arma1");
  short_desc = "Western part of the Armenian Quarter";
  long_desc =
"This is western part of the Armenian Quarter of Jerusalem.\n" +
"Living here seems a bit more normal than in the areas to your\n" +
"south and southwest. It is far from luxurious, however.\n" +           
"The residences here are very plain, and the only shops here\n" +
"are a few stores from which you can buy food. You notice some\n" +
"unordinary building to your south.\n";
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


