inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/watchman2.c");
move_object(monster, this_object());

}
if(arg) return;

add_exit("stairs","/wizards/irmeli/castle/wall6.c");
add_exit("west","/wizards/irmeli/castle/wall4.c");

short_desc = "Crossing of south and east wall of the castle of Asgroth";
long_desc = "A small guardhouse made of bricks and boards has been built in here, in the\n"+
            "crossing of the east and the south wall. The small guardhouse was built as a\n"+
            "shelter, shelter from the wind, attackers and cold for the watchmen. It even\n"+
            "has a roof which gives shelter on the rainy days. The guardhouse consists of\n"+
            "two exits: to the south wall and to the east wall, four walls, roof and one\n"+
            "window which gives a view to the outworld. A telescope is pointing through the\n"+
            "window to the outworld. You can hear the wind raping the walls and the roof\n"+ 
            "of the guardhouse. If the wind was a little bit stronger, it could take the\n"+
            "guardhouse along with it and smash it down to the ground. There are stairs\n"+
            "leading down to the east wall. There are two big towers rising up to the sky\n"+
            "from the north wall.\n";

  items = allocate(2);
  items[0] = "telescope";
  items[1] = "A rusty telescope is pointing through the window to the outworld. Its glass is broken and therefore it's useless.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}

