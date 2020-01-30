inherit "room/room";

// area loc changed by C 22.05.04
#define OUT	"outmap: 277 110"

reset(arg) {
        if(arg) return;
        add_exit("northwest",OUT);
        add_exit("north",OUT);
        add_exit("northeast","/wizards/rag/ruins/ruins_se");
        add_exit("west",OUT);
        add_exit("east",OUT);
        add_exit("southwest",OUT);
        add_exit("south",OUT);
        add_exit("southeast",OUT);

        short_desc = "Edge of ruins";
        long_desc =     "A raging storm blocks you vision. Some kind of a building seems\n"+
                        "to be located further to the north, but your path is blocked by\n"+
                        "an old stone wall. The howling of the wind sends chills down\n"+
                        "your spine. Small bushes grow here and there, but otherwise the\n"+
                        "area is quite desolate. A muddy path leads northeast.\n";

        items = allocate(8);
        items[0] = "building";
        items[1] = "It must be the long lost church";
        items[2] = "wall";
        items[3] = "The wall is very old but it's still very sturdy. It is covered with vines";
        items[4] = "vines";
        items[5] = "The vines grow against the wall. They aren't strong enough to be climbed";
        items[6] = "bushes";
        items[7] = "Stunted bushes try to manage here";

        set_sound(16+random(6),"Rain pours heavily down from the sky.\n");
        set_sound(25+random(6),"Thunder and lightning rage over the building.\n");
}
