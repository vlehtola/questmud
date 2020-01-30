

inherit "room/room";
object cata;
reset(arg) {

if(!cata) {
  cata = clone_object("/wizards/irmeli/castle/object/catapult.c");
  move_object(cata, this_object());
}

if(arg) return;
        set_light(4);

short_desc = ("In front of the castle of Asgroth");
long_desc= 
"A huge castle has been built here a long time ago. There is a sign on the other\n"+
"side of the moat. 'Castle of Asgroth' has been written on the sign. A deep moat\n"+
"surrounds the castle. It's full of crystal-clear water and hungry crocodiles.\n"+
"The one and only entrance to the castle is the drawbridge at the other side\n"+
"of the moat. The drawbridge has been pulled up. The walls of the castle\n"+
"are so high that it's impossible to climb up.\n";

add_exit("leave","/wizards/moonstar/areas/asgroth/virtual_map: 30 20");

items = allocate(2);
items[0] = "sign";
items[1] = "'Castle of Asgroth' has been written on the sign with big white letters.";

 call_other("wizards/irmeli/castle/drop_rock_d.c", "start_rocks", 1);
}
