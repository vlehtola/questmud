object sh1, sh2, dog;
reset (arg) {
    if(arg) return;
 short_desc = "Cow field";
 long_desc = "The earth is quite rich here and grows green grass. Grass is short\n"+
             "though, as some farms' animals have eaten it quickly. Ground is flat\n"+
             "and perfect place to keep a flock of sheep in. A battered wooden fence\n"+
             "blocks the way and only exit is to the north.\n";

add_exit("west","/wizards/neophyte/farm/room4");
add_exit("south","/wizards/neophyte/farm/room11");
items = allocate(4);
items[0] = "fence";
items[1] = "A wooden fence. It looks battered";
items[2] = "grass";
items[3] = "Short, green grass is growing here";
            ch1 = clone_object("/wizards/neophyte/farm/monst/sheep");
                        move_object(ch1, this_object());
            ch2 = clone_object("/wizards/neophyte/farm/monst/sheep");
                        move_object(ch2, this_object());
            dog = clone_object("/wizards/neophyte/farm/monst/dog");
                        move_object(dog, this_object());
}
