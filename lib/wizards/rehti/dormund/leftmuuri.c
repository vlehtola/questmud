inherit "room/room";

reset(arg) {
  add_exit("east","/wizards/rehti/dormund/hall");  
  add_exit("up","/wizards/rehti/dormund/l1");
  short_desc = "West wall entrance";
  long_desc = "Sunlight enters this room through hole in the roof. There is a ladder which\n"+
              "can be used to climb to the walls at west side of fortress. Moss grows only at\n"+
              "that part of wall which sunlight reaches. To the east is the main hall\n";
}