int wall;
inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("backward","/wizards/luminarc/mountain/cave11");
  add_exit("forward","/wizards/luminarc/mountain/cave13");
  short_desc="Cave";
  long_desc="Cave continues to deeper in the ground. The ice covering walls\n"+
            "is getting thicker and thicker. Floor in here is also ice covered\n"+
            "Some small cracks can be noticed on left side of the wall, some \n"+
            "light is emitting from there.\n";
  property = allocate(1);
  set_light(3);
add_action("smash", "smash");
}

smash(str)
{
if (str=="wall")
        if (wall==1)
        {
                write("The left side of the wall collapses!\n");
                wall = 1;
                add_exit("hole", "/wizards/luminarc/mountain/hole");
        return 1;
        }
        if (wall!=1) { return 1; }
       write("Break what?!\n");
} 
