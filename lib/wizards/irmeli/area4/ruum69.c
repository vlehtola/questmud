inherit "room/room";

object monster;



reset(arg) {

  if(!present("witch")) { 

    move_object(clone_object("/wizards/irmeli/area4/witch.c"),

    this_object());

}  



  if(arg) return;



  add_exit("down","/wizards/irmeli/area4/ruum68.c");



  short_desc = "At the top of the Orthanc, tower of death";

  long_desc = "You finally made it trought the mysterious tower and now there is only one\n"+

                "test left. The lightning strikes around the tower, making the tower shake\n"+

                "a bit. The wind blows now faster raping your face and body. There is a\n"+

                "big pot in front you, where the evil witch cooks its victims.\n";

}            

