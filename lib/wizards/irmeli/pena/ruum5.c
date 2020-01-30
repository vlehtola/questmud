inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 3")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelfig.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angelfig.c"), 
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angelfig.c"),
    this_object());
}
  
  if(arg) return;

  add_exit("north","/wizards/irmeli/pena/ruum7.c");
  add_exit("west","/wizards/irmeli/pena/ruum3.c");
 
  short_desc = "Small path in the Valley of Angels";
  long_desc = "You are walking on a small path. It is smaller than earlier ones. There are\n"+
                "some spiderwebs on the trees. There are few spiders on the path looking\n"+
                "you. Some of them are big and hairy.\n";   
}


