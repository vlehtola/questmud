inherit "room/room";
object monster;

reset(arg) {
  if(!present("keeper")) {
    move_object(clone_object("/wizards/neophyte/city/monst/keeper"),
    this_object());
 }

    if(arg) { return; }

        short_desc = "In front an old, ramshackled lighthouse";
        long_desc = "A high lighthouse has been built on the top of hills. It was built to warn the\n"+
                    "ships from the island and the range of rocks around it. Many ships have been\n"+
                    "sunked near the island by grounding, in consequence of thick mist or raging\n"+
                    "storm. There's an eternal flame burning on the top of the lighthouse. The\n"+
                    "lighthouse is old and ramshackled, paint with white and red paint, so that it\n"+
                    "would be easier to notice from the sea. The strong wind is blowing from the\n"+
                    "sea, shaking the lighthouse a bit. A thick mist is floating over the whole\n"+
                    "island, blanketing the visibility to the sea and from the sea.\n"+
                    "An iron door is leading inside the lighthouse (locked).\n";

    add_exit("north","/wizards/duncan/island/virtual_map: 65 9");
    add_exit("south","/wizards/duncan/island/virtual_map: 65 9");
    add_exit("east","/wizards/duncan/island/virtual_map: 65 9");
    add_exit("west","/wizards/duncan/island/virtual_map: 65 9");
    add_exit("northeast","/wizards/duncan/island/virtual_map: 65 9");
    add_exit("northwest","/wizards/duncan/island/virtual_map: 65 9");
    add_exit("southeast","/wizards/duncan/island/virtual_map: 65 9");
    add_exit("southwest","/wizards/duncan/island/virtual_map: 65 9");

    items = allocate(4);
    items[0] = "lighthouse";
    items[1] = "The lighthouse is old and ramshackled, paint with white and red paint. An eternal flame is burning on the top of the lighthouse";
    items[2] = "door";
    items[3] = "The iron door is locked. It leads inside the lighthouse";

    property = allocate(3);
    property[0] = "no_spell";
    property[1] = "no_skill";
    property[2] = "no_kill";

    }
