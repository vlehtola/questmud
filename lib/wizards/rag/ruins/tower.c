inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("down","/wizards/rag/ruins/church2");
        add_exit("east","/wizards/rag/ruins/library");

        short_desc = "In the bell tower";
        long_desc =     "Thunder rages outside the bell tower. The tower is wavering slightly\n"+
                        "because of the fierce storm. Two bronze bells are hanging from the roof.\n"+
                        "Obviously the force that raided the church didn't come up here. Perhaps\n"+
                        "they burned the stairs first. The rain has made the floor slippery. Tall\n"+
                        "windows open to each direction but you can't really see a thing. Stairs\n"+
                        "lead down back to the church and a small corridor leads east.\n";

        set_not_out(1);
        items = allocate(2);
        items[0] = "bells";
        items[1] = "The bells are not very big but they seem effective";

        set_sound(29+random(6),"You hear the pouring rain and the raging thunder.\n");
}
