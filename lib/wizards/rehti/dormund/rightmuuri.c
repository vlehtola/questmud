inherit "room/room";

reset(arg) {
  add_exit("west","/wizards/rehti/dormund/hall");  
  add_exit("up","/wizards/rehti/dormund/r1");
  short_desc = "East Wall entrance.";
  long_desc = "Sunlight enters this room through hole in the roof. There is a ladder which\n"+
              "can be used to climb to the walls at east side of fortress. Moss grows only at\n"+
              "that part of wall which sunlight reaches. To the west is the main hall\n";
}