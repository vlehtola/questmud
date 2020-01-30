inherit "room/room";
reset(arg) {
if(arg) return;

add_exit("back","/wizards/irmeli/castle/wtower3.c");


short_desc = "A small balcony in west tower";
long_desc = "A small balcony is built in the west tower. The balcony is made of\n"+
	    "wood and it's surrounded by a safety fence. There's a sea under\n"+
            "the balcony about forty meters from here. A cold and strong wind\n"+
            "blows from the sea. A door is leading back to the west tower.\n";

    set_light(3);

   items = allocate(4);
   items[0] = "safety fence";
   items[1] = "A safety fence is built around the balcony.";
   items[2] = "door";
   items[3] = "It leads back to the west tower.";


}
