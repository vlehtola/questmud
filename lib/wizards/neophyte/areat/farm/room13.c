inherit "room/room";
object ch1, ch2;
reset (arg) {
        if(!present("sheep")) {
        move_object(clone_object("/wizards/neophyte/areat/farm/monst/sheep"),this_object());
        }
        if(!present("sheep 2")) {
        move_object(clone_object("/wizards/neophyte/areat/farm/monst/sheep"),this_object());
        }
    if(arg) return;
 short_desc = "Grass field";
 long_desc = "The earth is quite rich here and grows green grass. Grass is short\n"+
             "though, as some farms' animals have eaten it quickly. Ground is flat\n"+
             "and perfect place to keep a flock of sheep in. A battered wooden fence\n"+
             "blocks the way to east and north.\n";

add_exit("west","room4");
add_exit("south","room14");
items = allocate(4);
items[0] = "fence";
items[1] = "A wooden fence. It looks battered";
items[2] = "grass";
items[3] = "Short, green grass is growing here";
}
