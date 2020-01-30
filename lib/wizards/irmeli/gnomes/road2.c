inherit "room/room";

object monster;

reset(arg) {

  if(!present("gnome")) {
    move_object(clone_object("/wizards/irmeli/gnomes/monsters/scout.c"),
    this_object());
}  
  if(arg) return;

  add_exit("east","/wizards/irmeli/gnomes/road4.c");
  add_exit("west","/wizards/irmeli/gnomes/road1.c");

  short_desc = "At the bank of a broad river";
  long_desc = "You are standing on the bank of a broad river. The river is so broad and flows\n"+ 
                "so fast, that there is no chance to swim to other side of the river from here.\n"+
                "There is not even a single tree growing at the other side of the river. It\n"+
                "seems, that all the trees has been chopped down. The bank of the river is\n"+
                "full of gravel sand.\n";
}










