inherit "room/room";  

reset(arg) {
  add_exit("west","/wizards/irmeli/area4/ruum18.c");
  set_not_out(1); 

  short_desc = "Inside the Dungeons of Orthanc, tower of death";
  long_desc = "You have arrived into dead end in Dungeons of Orthanc, tower of death. Here\n"+
                "rests many famous warriors, if the legends are true this was really\n"+
                "brutal place for outsiders. They tortured here as long as victim\n"+   
                "were dead, lots of prisoners died in these Dungeons. If you are\n"+
                "brave, you should go and look around these Dungeons.\n";
}
