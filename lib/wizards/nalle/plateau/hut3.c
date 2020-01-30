#define AREAPATH "wizards/nalle/plateau/"

inherit "room/room";

object monster;

reset(arg) {
  if(arg) return;
  add_exit("out",AREAPATH+"9_-3");
  short_desc = "Inside a warm shack";
  long_desc =
"This shack is quite cosy, but a bit messy. There is a fireplace in\n"+
"the corner and there is a small fire in it. Some light shines in\n"+
"from a small window, lighting the small particles of dust that fly\n"+
"silently across the room.\n";

if(!monster)    {
 monster = clone_object(AREAPATH+"monsters/armin");
 move_object(monster, this_object());
                }
}

