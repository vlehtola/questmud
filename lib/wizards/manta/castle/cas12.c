#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon14,mon15;

init() {
        add_action("enter", "enter");
        ::init();
}

extra_reset()   {
        if(!mon14)      {
        mon14 = clone_object("/wizards/manta/hill/mon3.c");
        move_object(mon14, this_object());
        }
      if(!mon15)        {
        mon15 = clone_object("/wizards/manta/hill/mon3.c");
        move_object(mon15, this_object());
        }
}

long(str) {
        ::long(str);
        if (str == "wall") {
                write("As you look western wall you see small hole in it.\n");
        }
        if (str == "hole") {
                write("This hole seems to lead to another room.\n");
                write("You feel great evil inside hole maybe you should leave?\n");
        }
}

id(str) {
        ::id(str);
        if (str == "wall") { return 1; }
        if (str == "hole") { return 1; }
}

enter(str) {
        if(str == "hole"){
        write("You enter a dark hole.\n");
        say(this_player()->query_name()+" enters a dark hole.\n");
         move_object(this_player(), "/wizards/manta/hill/room11.c");
        say(this_player()->query_name()+" enters room through hole.\n");
        return 1;
        }
        else {
        write("Enter where?\n");
        return 1;
        }
}       
                        
THREE_EXIT("/wizards/manta/castle/cas17.c", "north",
            "/wizards/manta/castle/cas13.c", "east",
            "/wizards/manta/castle/cas6.c", "south",
            "A castle tavern",
            "You have entered castle tavern, here has been fiersome battle\n" +
          "avalonians sore had fought for this. You notice that entire western\n" +
            "wall has been thorn down.\n", 2)

