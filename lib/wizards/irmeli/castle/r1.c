inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/guard.c");
move_object(monster, this_object());
}
if(arg) return;
short_desc = "Entrance to the castle of Asgroth";
long_desc = "At last you are standing in front the gateway to the castle. The castle of\n"+
            "Asgroth has been built centuries ago. The walls are in bad condition. The\n"+
            "ceiling is full of small holes, called as 'death holes'. From the holes\n"+  
            "the defenders of the castle were able to dump hot water on attackers. The\n"+
            "attackers faced a cruel death as they burnt alive. The rumours say, that\n"+
            "this castle was never conquered. A huge iron gate is preventing the entry\n"+
            "to the castle. A small lever is attached to the wall next to the gate.\n";
           
set_light(4);

items = allocate(4);
items[0] = "lever";
items[1] = "A small rusty lever attached to a wall. Times ago it was used for\n"+ 
           "opening the gate and the drawbridge. It can be lifted or lowered.";
items[2] = "gate";
items[3] = "The gate is made of iron, therefore it's very rusty.";

}
init() {
  ::init();
  add_action("lift", "lift");
  add_action("lower", "lower");
}

lift(str) {
  if(str != "lever") return;
  if(present("guard", this_object())) {
write("As you try to lift lever the guard grabs on your hand.\n"+
      "Guard says: 'You can enter to the castle only over my dead body.'\n");
 return 1;
}
write("You gather all your strength and pull the lever up.\n"+ 
      "Slowly the huge iron gate opens.\n");
    add_exit("gate", "wizards/irmeli/castle/yard.c");
  return 1;
}

lower(str) {
  if(str != "lever") return;
  write("You gather all your strength and lower the lever.\n"+ 
        "Slowly the drawbridge stars to open.\n"+
        "You walk over the drawbridge.\n");
    move_object(this_player(),"/wizards/irmeli/castle/entrance.c");
    this_player()->look();    
  return 1;
}