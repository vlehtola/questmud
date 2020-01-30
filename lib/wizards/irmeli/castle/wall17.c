inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/watchman.c");
move_object(monster, this_object());

}

if(arg) return;

add_exit("north","/wizards/irmeli/castle/wall16.c");
add_exit("south","/wizards/irmeli/castle/wall18.c");

short_desc = "West wall of the castle of Asgroth";
long_desc = "Looking west from here can be seen a far-reaching and thick forest in its\n"+
            "entirety. Among the trees, there seems to be a couple higher ones, reaching\n"+
            "as high as the castle's west wall. The west wall is disintegrating in front\n"+
            "of your eyes. One rock loosens from the wall and hits to the yard, only\n"+
            "couple of seconds after it loosened from the wall. It rises a huge cloud of\n"+  
            "dust on the yard. You can see people running recklessly in the yard. The\n"+
            "deep moat in the ground is full of clear water. There are no fence on the\n"+
            "wall. A strong and cold wind is blowing hard against the west wall. Towards\n"+
            "south is the south wall which is twenty meters higher than the other walls.\n"+ 
            "In north can be seen two massive towers rising up to the sky, reaching\n"+
            "almost to the cloudline.\n"; 
           
  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
