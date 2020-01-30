inherit "room/room";
object mon;

reset(arg) {

        if(arg) return;

        if(!mon) {
                mon = clone_object("/wizards/rag/elf/monsters/celebmir");
                move_object(mon, this_object());
        }

        add_exit("east","/wizards/rag/elf/u_d4");

        short_desc = "Inside the mighty oaks";
        long_desc =     "This seems to be somekind of a study. There are\n"+
                        "many bookshelves and a table here. Several candles\n"+
                        "light the room. There are scrolls, maps and clothes\n"+
                        "scattered all over the floor and the table. There\n"
                        "are miscellenous books and potions on the shelves.\n"+
                        "A bed is located between two massive oak branches.\n";

        items = allocate(12);
        items[0] = "table";
        items[1] = "There are some books on the table";
        items[2] = "books";
        items[3] = "Most of the books tell about the rise of an ancient evil";
        items[4] = "shelves";
        items[5] = "The shelves are filled with dusty books and some potions";
        items[6] = "maps";
        items[7] = "The maps are from all over the world";
        items[8] = "potions";
        items[9] = "You are too afraid to taste the potions";
        items[10] = "scrolls";
        items[11] = "All kinds of songs and tales are written on the scrolls";

        set_light(2);
}
