string arg1, arg2;
int arg3;
int i;

inherit "room/room";


reset(arg) {

  add_exit("north","/wizards/bulut/catacombs/room7");
  add_exit("west","/wizards/bulut/catacombs/room4");
  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
              "A dried up tree makes clattering sounds as wind blows by it.\n" +  
              "Someone should cut that tree, it looks like it could collapse\n" +
	      "any minute now.\n" +
	      "No one seems to be taking care of this old graveyard.\n";
  set_light(2);                 
  
}

init() {
::init();
add_action("look","look");
}


look(str) {
if (!str) { return 0; }
if(sscanf(str,"%s %s", arg1,arg2)) {
	if(arg1=="at") {
		if(arg2=="tree") {
		write("A big dried up tree, there are some holes in it.\n");
		return 1;
		}
		if(arg2=="holes") {
		write("There are at least four holes in the tree.\n");
		return 1;
		}
		if(arg2=="hole") {
		write("Look at which hole?\n");
		return 1;
			 	 }
			}
		}
if(sscanf(str,"%s %s %d", arg1,arg2,arg3)) {
	if(arg1=="at") {
		if(arg2=="hole") {
			if(arg3==1) { write("Nothing in there\.n"); return 1;}
			if(arg3==2) { write("Just some rotten moss.\n"); return 1; }                      
			if(arg3==3) { write("Nothing in there.\n"); return 1;}
			if(arg3==4) { 
				if(!i) {
			 	 write("You found a book!\n");
         			 move_object(clone_object("/wizards/bulut/catacombs/book"), this_player());
				 i=1;
				 return 1;
				       }
				return 0;
				}
		return 0;
	}
	return 0;
}        
	return 0;
}   
}             