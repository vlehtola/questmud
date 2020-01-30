inherit "room/room";
int i;

reset(arg) {

        add_exit("east","/wizards/jenny/gnael/huoneet/city8.c");

        if(arg) return;
        i = 0;

        short_desc = "Hidden room inside the wall";
        long_desc = "You have arrived to a hidden room inside the city wall. The room\n"+ 
                        "looks ancient and there is dust and some spider webs all over\n"+
                        "the place. There is a small wooden table in the far east corner\n"+
                        "of the room and you can see some books on the table as well.\n";

        items = allocate(10);
        items[0] = "dust";
        items[1] = "Just a normal dust";
        items[2] = "webs";
        items[3] = "Very old spider webs are hanging all over the room";
        items[4] = "table";
        items[5] = "A small wooden table";
        items[6] = "books";
        items[7] = "There is something fishy in one the books";
        items[8] = "book";
        items[9] = "This book radiates strangely";
}
 
search_finished(str) {
        if(!i && str == "book") {
                object heart;
                write("You open the book and find heart inside it\n");
                say(this_player()->query_name()+ " starts to inventigate a book\n");
                heart = clone_object("/wizards/jenny/gnael/rojut/heart.c");
                move_object(heart, this_player());
                i = 1; 
                return 1;
        }
        if(i && str == "book") {
                write("You open the book, but there is nothing inside it\n");
                say(this_player()->query_name()+ " looks disappointed\n");
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}
