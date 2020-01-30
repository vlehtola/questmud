inherit "room/room";

object monster;

reset(arg)  {
set_light(0);
set_not_out(1);
            add_exit("up", "/wizards/irmeli/nyx/ruin1");
            short_desc = "Storage cellar, under the ancient ruins";
long_desc = "A small storage cellar under the ancient ruins. The rocky walls, ground\n"+
            "and ceiling are all rough and cold. The walls are full of ancient marks.\n"+
            "An old and rotten skeleton is lying on the ground.\n";
items = allocate(4);
items[0] = "marks";
items[1] = "There are some reading on the marks which says: 'Do t l  k a th sk let n'";
items[2] = "skeleton";
items[3] = "An old and totally rotten skeleton is lying on the ground. It's probably one of the thousands victims of the volcanic eruption";
}

long(str) {
    ::long(str);
    if (str == "skeleton") {
        if (!monster) {
          monster = clone_object("/wizards/irmeli/nyx/monsters/demon");
          move_object(monster, this_object());
          say("Suddenly a horrible demon jumps behind the rotten skeleton.\n");
          tell_object(this_player(), "Suddenly a horrible demon jumps behind the rotten skeleton.\n");
          this_player()->set_quest("find_demon", 2);
        }
        call_other("/wizards/aarrgh/nyxi/down1.c","set_looked",1);
    }
}
