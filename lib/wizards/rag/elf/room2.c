inherit "room/room";
object monster;

reset(arg) {
        if(!monster) {
         monster = clone_object("/wizards/rag/elf/monsters/hare");
         move_object(monster, this_object());
        }
        if(arg) return;

        add_exit("west","/wizards/rag/elf/w_g2");
        add_exit("south","/wizards/rag/elf/room1");
        add_exit("east","/wizards/rag/elf/e_g1");

        short_desc = "By a small river";
        long_desc = "A small river is flowing here. It flows from east\n"+
                        "and continues to west. There seems to be no way\n"+
                        "to cross the river. All kinds of trees and bushes\n"+
                        "grow here. The path continues to west and east.\n";

        items = allocate(6);
        items[0] = "trees";
        items[1] = "You see sturdy lookings oaks and slender birches";
        items[2] = "bushes";
        items[3] = "You see bushes full of berries";
        items[4] = "river";
        items[5] = "You see a fish swimming in the clear water";
}
