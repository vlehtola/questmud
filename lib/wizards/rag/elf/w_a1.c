inherit "room/room";
inherit "room/door";
object block;

reset(arg) {
        if(!block) {
                block = clone_object("/wizards/rag/elf/monsters/orc_n");
                move_object(block, this_object());
        }
        if(!present("orc 2")) {
                move_object(clone_object("/wizards/rag/elf/monsters/orc"), this_object());
        }
        if(!present("orc 3")) {
                move_object(clone_object("/wizards/rag/elf/monsters/orc"), this_object());
        }
        if(arg) return;

        add_exit("southeast","/wizards/rag/elf/w_b1");

        short_desc = "In the cave";
        long_desc = "This room looks just like the other rooms, but there's a massive\n"+
                        "door here. There must be something important behing the door because\n"+
                        "it's guarded heavily. The door seems to be very sturdy.\n";

        door_reset();
        set_door_label("oaken door reinforced with bronze",1);
        set_door_dir("north", "/wizards/rag/elf/orcroom",1);
        set_door_link("/wizards/rag/elf/orcroom",1);
        set_door_code("817", 1);
        set_locked(1, 1);

        set_not_out();
        set_sound(30+random(60),"You hear some arcane chants from behind the door.\n");
}

init() {
  ::init();
  door_init();
}
