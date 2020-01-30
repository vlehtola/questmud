inherit "room/room"; 
 
int location,direction;
 
reset(arg) {
   short_desc = "On the ferry";
   long_desc = "You are on a ferry of some sort. It is not big, and it seems that if the wind amplifies,\n"+
                 "you would be in a lot of trouble, since there are only meager bords around it.\n"+
                 "It seems that there is no one steering the whole thing, but it is being pulled from\n" +
                 "somewhere.\n";
   set_not_out(1);
   add_exit("cabin", "wizards/walla/peepseye/ferry/cabin.c");
   set_light(3);
}
 
start_ferry() {
location = 1;                   
   add_exit("south", "wizards/walla/peepseye/kitty/dock.c");
   call_other("wizards/walla/peepseye/kitty/dock.c", "add_exit","north", "wizards/walla/peepseye/ferry/ferry.c");
   call_out("change_pos",30);
}
 
change_pos() {
  
   if (location == 1) {
        tell_room(this_object(), "The ferry jerks, and starts moving towards the unknown.\n");
        tell_room("wizards/walla/peepseye/kitty/dock","The ferry starts moving away from the dock.\n");
        call_other("wizards/walla/peepseye/kitty/dock.c", "remove_exit", "north");
        remove_exit("south");
 call_out("real_move", 169);                       
   }
if (location == 2) {
 
           tell_room(this_object(), "The ferry leaves, leaving a trail behind.\n");
           tell_room("wizards/walla/peepseye/ferry/ferry","The ferry rolls over the waves.\n");
          call_other("wizards/walla/peepseye/1.c", "remove_exit", "south");
          remove_exit("north");
          call_out("real_move", 169);
   }
}
 
real_move() {
   tell_room("wizards/walla/peepseye/ferry/ferry.c", "The ferry arrives.\n");
if (location == 1) {                   
   tell_room("wizards/walla/peepseye/kitty/dock","The ferry arrives.\n");
  
        call_other("wizards/walla/peepseye/1.c", "add_exit","south","wizards/walla/peepseye/ferry/ferry.c");
        add_exit("north", "wizards/walla/peepseye/1.c");
        location = 2;
        call_out("change_pos", 30);
        return 1;
   }
   if (location == 2) {
 
           tell_room("wizards/walla/peepseye/kitty/dock", "The ferry arrives.\n");                               
           call_other("wizards/walla/peepseye/kitty/dock.c", "add_exit","north","wizards/walla/peepseye/ferry/ferry.c");
           add_exit("south", "wizards/walla/peepseye/kitty/dock.c");
           location = 1;
 
 
 call_out("change_pos", 30);
        return 1;
   }
}
