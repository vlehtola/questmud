inherit "room/room";
object ob;
status i;
reset(arg) {
if(arg) return;

short_desc = "Inside the tomb";
long_desc =  "The tomb is beautifully decorated with golden statues and\n"+
             "pictures of sailors. A large coffin lays on the center of\n"+
             "the tomb and the lid is broken, what has been inside the coffin\n"+
             "is now robbed and all the expensive items are gone. Looks like\n"+
             "someone is moving behind the coffin and mumbling something.\n";
  add_exit("out", "room3");
        property = allocate(1);
        property[0] = "no_summon";
        set_not_out();
        set_light(1);
       items = allocate(6);
	   items[0] = "coffin";
       items[1] = "As you look in the coffin you see nothing special all the expensive items are gone but then you see something moving behind the coffin, maybe you should search little carefully";
       items[2] = "statues";
       items[3] = "A small golden status what are representing boats and sailors";
       items[4] = "lid";
       items[5] = "Lid of the coffin is broken and all the valuable things are removed from coffin";
}

search_finished(str) {
        if(!i || str == "coffin") {
                write("As you look behind the coffing a thief jumps out and attacks!\n");
                say(this_player()->query_name()+ " founds something.\n");
            	ob = clone_object("/wizards/neophyte/city/monst/regor");
               	move_object(ob,this_object());
               	this_player()->attack_object(ob);
                i = 1;
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}