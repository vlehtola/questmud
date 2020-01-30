inherit "room/room";
 
int location,direction;
 
reset(arg) {
   short_desc = "In a huge pot";
   long_desc = "This is nothing but a mere pot. It seems to have been used to fry lard in an earlier\n"+
               "era, well, at least it smells that way. The pot has for purpose to bring draconians\n"+
               "from one level to another. It seems that the whole machine works by a chain pulled from\n" +
               "somewhere.\n";
   set_not_out(1);
   add_exit("chains", "wizards/walla/dl/rooms/xaktsaroth/pot_up_chains.c");
   set_light(3);
}
 
start_ferry() {
 location = 1;
   add_exit("out", "wizards/walla/dl/rooms/xaktsaroth/pot_room_up.c");
   call_other("wizards/walla/dl/rooms/xaktsaroth/pot_room_up.c", "add_exit","pot", "wizards/walla/dl/rooms/potup.c");
   call_out("change_pos", 10);
}
 
change_pos() {
 
   if (location == 1) {
        tell_room(this_object(), "The pot starts swinging upwards.\n");
        tell_room("wizards/walla/dl/rooms/xaktsaroth/potup.c","The pot jerks and moves slowly upwards.\n");
        call_other("wizards/walla/dl/rooms/xaktsaroth/pot_room_up.c", "remove_exit", "pot");
        remove_exit("out");
 call_out("real_move", 21);
   }
if (location == 2) {
 tell_room(this_object(), "The pot starts moving slowly back down.\n");          
         tell_room("wizards/walla/dl/rooms/xaktsaroth/potup.c","The pot slowly start descending.\n");
         call_other("wizards/walla/dl/rooms/xaktsaroth/chiefroom.c", "remove_exit", "pot");
         remove_exit("out");
         call_out("real_move", 21);
   }
}
 
real_move() {
   tell_room("wizards/walla/dl/rooms/xaktsaroth/potup.c", "The pot seems to have arrived at it's final location.\n");
if (location == 1) {
   tell_room("wizards/walla/dl/rooms/xaktsaroth/pot_room_up.c","The pot will go no further.\n");
 
        call_other("wizards/walla/dl/rooms/xaktsaroth/pot_room_up.c", "add_exit","pot","wizards/walla/dl/rooms/xaktsaroth/potup.c");
        add_exit("out", "wizards/walla/dl/rooms/xaktsaroth/pot_room_up.c");
        location = 2;
        call_out("change_pos", 10);
        return 1;
   }
   if (location == 2) {
 
        tell_room("wizards/walla/dl/rooms/xaktsaroth/chiefroom.c", "The pot arrives to a complete halt.\n");
        call_other("wizards/walla/dl/rooms/xaktsaroth/chiefroom.c", "add_exit","pot","wizards/walla/dl/rooms/xaktsaroth/potup.c");
        add_exit("out", "wizards/walla/dl/rooms/xaktsaroth/chiefroom.c");
        location = 1;
        call_out("change_pos", 10);
        return 1;
   }
}

