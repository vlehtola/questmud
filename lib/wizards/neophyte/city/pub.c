inherit "room/room";
object lasca;
reset (arg) {
    if(arg) return;
            if(!lasca) {
	                lasca = clone_object("/wizards/neophyte/city/monst/lasca");
	                move_object(lasca, this_object());
	        }
        short_desc = "Seventh sea inn";
        long_desc = "You just stepped in to the seventh sea inn. There are lots of drunken\n"+
                    "sailors, pirates and travellers from the distant cities sitting on the\n"+
                    "tables. The tables are full of mugs and trashes, that's why this place\n"+
                    "looks like dump. A nice fireplace has been built near the north wall of\n"+
                    "the inn. A huge candle lamp is hanging from the ceiling, lighting up\n"+
                    "the whole inn. The stairs are leading upwards to the another floor.\n";
        set_not_out(1);
   set_light(3);
   add_exit("south","/wizards/neophyte/city/anchor3");
   add_exit("up","/wizards/neophyte/city/pub1");
   items = allocate(6);
   items [0] = "tables";
   items [1] = "Almost every table is reserved by the drunken people";
   items [2] = "fireplace";
   items [3] = "It's build from red bricks, which are now sooth and black";
   items [4] = "lamp";
   items [5] = "A huge candle lamp has quite few candles still burning";
}
