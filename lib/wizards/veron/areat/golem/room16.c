inherit "room/room";


object monster;
int sammu;

reset(arg) {
set_not_out(1);
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/fgolem");
    move_object(monster, this_object());
sammu = 0;
   

}

add_exit("north","/wizards/veron/areat/golem/room18.c");
add_exit("south","/wizards/veron/areat/golem/room15.c");



  short_desc = "A room with a fireplace";
if(sammu == 0) {
  long_desc = "This room is very hot. A large fireplace in the eastern wall \n"+
		  "dominates the room. Fire crackles inside it. A wooden box full of \n"+
		  "firewood is placed next to the fireplace. There's a comfortable-looking \n"+
		  "sofa in front of the fireplace. Some small, metallic sticks lean to the\n"+
	        "sofa. A small bag is placed on the sofa.\n";
  }
else {
long_desc = "This room is very hot. A large fireplace in the eastern wall \n"+
		    "dominates the room. There's no fire in it. A wooden box full of \n"+
		    "firewood is placed next to the fireplace. There's a comfortable-looking \n"+
		    "sofa in front of the fireplace. Some small, metallic sticks lean to the\n"+
	          "sofa. A small packet is placed on the sofa. A ladder leads up to the \n"+
		    "chimney in the fireplace.\n";
}  



      
		  
  items = allocate(10);
  items[0] = "box";
  items[1] = "A wooden box full of firewood";
  items[2] = "sticks";
  items[3] = "Metallic, fork-like sticks with wooden handles. Great for frying sausages";
  items[4] = "bag";
  items[5] = "A small packet made of leather. It includes four sausages.\n"+
             "They look absolutely delicious";
  items[6] = "fireplace";
  items[7] = "A nice large fireplace with fire crackling inside it. There's something weird in \n"+
		 "it, but the fire's in the way"; 
  items[8] = "sofa";
  items[9] = "A comfortable-looking fluffy sofa";


}
init() {
  ::init();
  add_action("hep", "extinguish");
  
 }
hep(str) {
    
    if(str == "fire with water") {
    if(!sammu) {
    if(present("bucket", this_player()) && !present("bucket", this_player())->query_no_save()) {

    write("You throw the bucket in the fireplace extinguishing the fire. You spot a ladder\n"+
          "leading up to the chimney.\n");
    say(this_player()->query_name() + " extinguishes the fire by throwing a bucket full of water in it. You spot\n"+
			"a ladder leading up in the chimney.\n");
 this_player()->set_quest("Find the secret exit in the Mansion");

    

    sammu=1;
    
   

    destruct(present("bucket", this_player()));
    add_exit("ladder","zikkrit.c");
  long_desc = "This room is very hot. A large fireplace in the eastern wall \n"+
		    "dominates the room. There's no fire in it. A wooden box full of \n"+
		    "firewood is placed next to the fireplace. There's a comfortable-looking \n"+
		    "sofa in front of the fireplace. Some small, metallic sticks lean to the\n"+
	          "sofa, and a small packet is placed on the sofa. A ladder leads up to the \n"+
		    "chimney in the fireplace.\n";


        
  items[6] = "fireplace";
  items[7] = "A nice large fireplace. There's a ladder leading up to the chimney";

return 1;

}


 else { 
 write("Do what?");
return ;
}
}
else {
	return;
}
}

}
