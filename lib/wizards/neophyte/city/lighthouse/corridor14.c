inherit "room/room";
int key;

reset(arg) {
if(arg) return;

set_not_out(1);
set_light(1);

short_desc = "A crashed down corridor";
long_desc =  "The ceiling has crashed in here and blocking the way\n"+
             "to go any deeper in this corridor. Lots of dust and smoke\n"+
             "is in the air, making breathing hard. Something is shimmering\n"+
             "in the pile of rocks.\n";

add_exit("east","corridor13");

  property = allocate(1);
  property[0] = "no_summon";
}

search_finished(str) {
        object key;
        if(key == 0 && str == "rocks") {
                write("You have found a shimmering key!\n");
                say(this_player()->query_name()+ " founds a shimmering key.\n");
                key = clone_object("/wizards/neophyte/city/obj/shimkey");
                move_object(key, environment(this_player()));
                key = 1;
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}
