inherit "room/room";
int deeth;
 
init() {
   ::init();
   if (find_call_out("valo") == -1) call_out("valo",1);
   
   
}
 
   valo() { 
   write("Apua, joku ampuaa sua.\n");
   say(this_player()->query_name()+" is being shot at.\n"); 
   deeth = 100;  
   this_player()->reduce_hp(deeth);
   return 1;
}
reset(arg) {
 
  add_exit("test","test");
  short_desc = "Grand place";
  long_desc =
"You are standing in the middle of the city. The walls can be seen\n" +
"in the distance. You notice that the ground has been newly paved\n" +
"with white marble from distant lands. A thing that strikes you, is\n" +
"the lack of animals in the town. The commotion in the city has not\n"
"quite yet started, as people have only just started settling.\n";
 
 
}
