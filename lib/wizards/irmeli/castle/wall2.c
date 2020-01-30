inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/wguard.c");
move_object(monster, this_object());

}
if(arg) return;

add_exit("east","/wizards/irmeli/castle/wall3.c");
add_exit("west","/wizards/irmeli/castle/wall1.c");

short_desc = "South wall of the castle of Asgroth";
long_desc = "The south wall is high. It's almost twenty metres higher than the other\n"+ 
            "walls. It must be more than fifty metres to the ground from here. There are\n"+
            "no fence around the wall, therefore you should be careful not to fall down.\n"+
            "The gate which you used to get inside to the castle is just below you.\n"+
            "A massive valley full of green grass, beautiful flowers, old trees and\n"+
            "thick bushes can be seen towards south. Not to forget the animals and the\n"+
            "broad river. The moat below you surrounds the castle walls. A strong\n"+
            "and cold wind is blowing hard but it has no effect to the south wall,\n"+
            "thanks to the strong gate. There are two big towers rising up to the sky\n"+
            "from the north wall.\n";
  
  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
