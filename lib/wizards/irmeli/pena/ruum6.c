inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 2")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelfig2.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angelfig2.c"), 
    this_object());
}
  
  if(arg) return;

  add_exit("south","/wizards/irmeli/pena/ruum4.c");
  add_exit("east","/wizards/irmeli/pena/ruum8.c");
 
  short_desc = "Small path in the Valley of Angels";
  long_desc = "You are walking on a small path. It is smaller than earlier ones. There are\n"+
                "some spiderwebs on the trees. There are few spiders on the path looking\n"+
                "you. Some of them are big and hairy.\n";   
}


