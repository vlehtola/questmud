#define AREAPATH "wizards/nalle/plateau/"

inherit "room/room";

object monster;

reset(arg) {
  if(arg) return;
  add_exit("out",AREAPATH+"12_0");
  short_desc = "Inside a hut made of clay";
  long_desc =
  "This is a small hut made of clay. The floor is littered with\n"+
  "bones and rotten plants, that have been intended as food, or\n"+
  "so it would seem. The inhabitant of this shack is obviously\n"+
  "not a very tidy person and you feel very reluctant just breating\n"+
  "the hut's foul air.\n";

 if(!monster)   {
 monster = clone_object(AREAPATH+"monsters/plainsman");
 move_object(monster, this_object());
                }

}

