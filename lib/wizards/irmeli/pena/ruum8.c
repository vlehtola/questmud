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

  add_exit("west","/wizards/irmeli/pena/ruum6.c");
  add_exit("east","/wizards/irmeli/pena/ruum7.c");
  add_exit("hole","/wizards/irmeli/pena/ruum9.c");
  add_exit("north","/wizards/irmeli/pena/ruum33.c");
  
  short_desc = "Small hill in the Valley of Angels";
  long_desc = "You are standing on a small hill. There is a small hole under your feets.\n"+
                "If you are small you might try to get in hole. You can hear noises\n"+
                "coming from hole.\n";   
}


