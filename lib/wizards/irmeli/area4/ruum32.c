inherit "room/room";
object monster;

reset(arg) {
  if(!present("gremlin")) { 
    move_object(clone_object("/wizards/irmeli/area4/gremlin4.c"),
    this_object());
}  

  if(arg) return;

  add_exit("south","/wizards/irmeli/area4/ruum33.c");
  add_exit("north","/wizards/irmeli/area4/ruum27.c");
  set_not_out(1);

  short_desc = "Floor three inside the Orthanc, tower of death";
  long_desc = "This is a long corridor leading you to southwards and northwards. The more\n"+
                "south you go the beatiful it gets. You have a strange feel like you\n"+
                "were in heaven or in dreams. You just want stop the time and live\n"+
                "hours and hours in this time. You need to get a grip on yourself\n"+
                "and continue the journey and defy dangers.\n";
}
