inherit "room/room";
object monster;
reset(arg) {

if(arg) return;
  if (!monster) {
      monster = clone_object("/wizards/siki/forest/monsters/dexlom");
      move_object(monster, this_object());
      }
        add_exit("out","room14");
        short_desc = "Inside the portal of darkness";
        long_desc = "Maddening vortex of lights is twirling in the center of this portal. Demonic roars can be heard from all directions, the mist is so thick that it almost pushes you to the ground. "+
                    "Deformed creatures are howling to the vortex, and the cacophony in this dark portal almost deadens you!\n";
}
