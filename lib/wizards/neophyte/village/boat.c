inherit "room/room";
reset(arg) {
        if(arg) return;
        short_desc = "Inside the boat";
        long_desc = "You are sitting one of the seats. The water is constantly waving the boat.\n"+
                    "On the surface of boat is lots of water looking like it might sink any minute.\n";
        }
init() {
	::init();
	call_out("perilla", 10);
}

perilla() {
	write("Finally the boat arrives at the ferry.\n");
move_object(this_player(), "/wizards/neophyte/village/hut6");
write("Goblin grins evilly and says: 'I have to go back to shore.\n");
write("Goblin tells you: 'You have to make your own way back.\n");
command("look", this_player());
return 1;
}
